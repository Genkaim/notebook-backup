import re, os, glob

MM = "MathModel"
files = glob.glob(os.path.join(MM, "*.md"))
def key(name):
    m = re.match(r'^(\d+)(?:\.(\d+))?', os.path.basename(name))
    return (int(m.group(1)), int(m.group(2)) if m.group(2) else 0) if m else (999,0)
files.sort(key=key)

mermaid_re = re.compile(r"```mermaid.*?```", re.DOTALL)

def clean_ctrl(s):
    return "".join(ch for ch in s if ord(ch) >= 32 or ch in "\n\t\r")

def fix(t):
    t = clean_ctrl(t)
    t = mermaid_re.sub("", t)
    # 双反斜杠环境还原
    t = t.replace("\\\\begin", "\\begin").replace("\\\\end", "\\end")
    # 裸 \( \) \[ \] -> $ $$  （搜索串必须双反斜杠表示字面反斜杠）
    t = t.replace("\\(", "$").replace("\\)", "$")
    t = t.replace("\\[", "$$").replace("\\]", "$$")
    for c in ["times","geq","le","ge","leq","sum","frac","sqrt","alpha","beta",
              "rightarrow","Rightarrow","cdots","text","min","max","infty","in",
              "notin","mathbb","mathbf","mathcal","vec","hat","bar","nabla","partial",
              "cdot","xi","sigma","lambda","mu","pi","theta","omega","Delta","forall",
              "exists","neq","approx","equiv","propto","cup","cap","subset","supset",
              "to","quad","qquad","exp","left","right","beta"]:
        t = t.replace("\\\\"+c, "\\"+c)
    for env in ("cases","array"):
        be = "\\begin{"+env+"}"; ee = "\\end{"+env+"}"; start=0
        while True:
            i = t.find(be, start)
            if i < 0: break
            if i>0 and t[i-1]== "$": start=i+len(be); continue
            j = t.find(ee, i)
            if j < 0: break
            if j+len(ee)<len(t) and t[j+len(ee)]=="$": start=j+len(ee); continue
            t = t[:i]+"$"+t[i:j+len(ee)]+"$"+t[j+len(ee):]
            start = j+len(ee)+2
    return t

out = [("\\newpage\n\n# "+os.path.basename(f)+"\n\n"+fix(open(f, encoding="utf-8").read())) for f in files]
open("_merged_mathmodel.md","w",encoding="utf-8").write("\n\n".join(out))
print("clean merge done, files:", len(files))
