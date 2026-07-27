\newpage

# 0.0 综述.md

## 0.0.1 评价类算法



\newpage

# 0.1 归一化.md


| **方法名称**                                     | **标准数学公式**                                                 | **几何本质**                                   | **核心特点与数据影响**                                          | **典型适用场景**                                                    |
| -------------------------------------------- | ---------------------------------------------------------- | ------------------------------------------ | ------------------------------------------------------ | ------------------------------------------------------------- |
| **Min-Max 归一化**<br>$(Min-Max Normalization)$ | $$z_{ij} = \frac{x_{ij} - x_{\min}}{x_{\max} - x_{\min}}$$ | **区间平移缩放**<br><br>将数据整体平移并缩放到 $[0, 1]$ 之间。 | **改变了原点和比例。**<br><br>因为减去了最小值，相当于移动了坐标轴，这会破坏原始向量的倍数关系。 | **神经网络输入**、支持向量机（SVM）。<br><br>（主要用于消除不同指标的数量级差异，不关心绝对距离）      |
| **比重归一化**<br>$(Sum Normalization)$           | $$z_{ij} = \frac{x_{ij}}{\sum_{i=1}^{n} x_{ij}}$$          | **总和单位化**<br><br>将每一列的数据之和缩放到 1。           | **转化为相对份额。**<br><br>处理后的数据全部变为正数（占比），天然具备概率或权重的物理含义。   | **[[1 层次分析法 AHP\|层次分析法]]（AHP）**、信息熵法。<br><br>（用于计算权重分布或分析贡献率） |


\newpage

# 0.2 标准化.md

| **标准化方法**                       | **公式**                                                    | **基本思想**                            | **特点**                              | **适用场景**                                           |
| ------------------------------- | --------------------------------------------------------- | ----------------------------------- | ----------------------------------- | -------------------------------------------------- |
| **向量归一化（Vector Normalization）** | $$z_{ij}=\frac{x_{ij}}{\sqrt{\sum_{i=1}^{n}x_{ij}^{2}}}$$ | 将每个指标对应的数据列进行单位化处理，使该指标列向量的欧氏范数为 1。 | 保持各样本在同一指标下的相对比例关系，仅消除量纲影响，不改变向量方向。 | TOPSIS 法、灰色关联分析（部分形式）、向量空间分析及其他基于欧氏距离或向量运算的综合评价方法。 |


|类型|代表方法|特点|典型应用|
|---|---|---|---|
|标量无量纲化|均值化、初值化、最大值化、区间化等|每个元素按本列统计量变换，结果易解释|熵权法、灰色关联、模糊综合评价等|
|向量归一化|$\displaystyle z_{ij}=\frac{x_{ij}}{\sqrt{\sum_i x_{ij}^2}}$|将整列向量长度归一为1，保留方向信息|TOPSIS、VIKOR 等基于欧氏距离的方法|


\newpage

# 0.3 正向化.md

若有矩阵$X = \begin{bmatrix} x_{11} & x_{12} & \dots & x_{1m} \\ x_{21} & x_{22} & \dots & x_{2m} \\ \vdots & \vdots & \ddots & \vdots \\ x_{n1} & x_{n2} & \dots & x_{nm} \end{bmatrix}$，有$n$个方案，$m$个指标。

不一定所有的指标都是越大越好，所以我们需要统一一下，保证每个指标都为递增为更好。

| 名称               | 处理办法                                                                                                                                                                            |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 极大型指标            | 不动                                                                                                                                                                              |
| 极小型指标            | $x_i'=max-x_i$，$max$为指标的最大值                                                                                                                                                     |
| 中间型指标（中间某个点为最优值） | $M=max\{\|x_i-x_{best}\|\}, x_i'=1-\frac{\|x_i-x_{best}\|}{M}$                                                                                                                  |
| 区间型指标（一个区间都为最优值） | $[a,b]$为最优区间，$M=max\{a-min\{x_i\},max\{x_i\}-b\}$,$x_i'=\begin{cases}1-\frac{a-x_i}{M}, \qquad x_i<a \\ 1, \qquad a \le x_i\le b \\ 1-\frac{x_i-b}{M}, \qquad b<x_i\end{cases}$ |


\newpage

# 0.4 统一量纲.md


| **序号** | **变换名称**       | **变换公式**                                                                                      | **约束条件 / 变量说明**                          |
| ------ | -------------- | --------------------------------------------------------------------------------------------- | ---------------------------------------- |
| **①**  | **均值化变换**，用的较多 | $$f(x(k)) = \frac{x(k)}{\bar{x}}$$                                                            | $\bar{x} = \frac{1}{n}\sum_{i=1}^n x(k)$ |
| **②**  | **初始值变换**      | $$f(x(k)) = \frac{x(k)}{x(l)}$$                                                               | $x(l) \neq 0$                            |
| **③**  | **百分比变换**      | $$f(x(k)) = \frac{x(k)}{\max\limits_{k} x(k)}$$                                               | --                                       |
| **④**  | **倍数变换**       | $$f(x(k)) = \frac{x(k)}{\min\limits_{k} x(k)}$$                                               | $\min\limits_{k} x(k) \neq 0$            |
| **⑤**  | **归一化变换**      | $$f(x(k)) = \frac{x(k)}{x_0}$$                                                                | $x_0$为大于零的某个值                            |
| **⑥**  | **最大值化变换**     | $$f(x(k)) = \frac{x(k) - \min\limits_{k} x(k)}{\max\limits_{k} x(k)}$$                        | -                                        |
| **⑦**  | **区间值化变化**     | $$f(x(k)) = \frac{x(k) - \min\limits_{k} x(k)}{\max\limits_{k} x(k) - \min\limits_{k} x(k)}$$ | -                                        |


|类型|代表方法|特点|典型应用|
|---|---|---|---|
|标量无量纲化|均值化、初值化、最大值化、区间化等|每个元素按本列统计量变换，结果易解释|熵权法、灰色关联、模糊综合评价等|
|向量归一化|$\displaystyle z_{ij}=\frac{x_{ij}}{\sqrt{\sum_i x_{ij}^2}}$|将整列向量长度归一为1，保留方向信息|TOPSIS、VIKOR 等基于欧氏距离的方法|

\newpage

# 1 层次分析法 AHP.md

## 1.1 模型思想

$AHP$将待研究问题分为不同的层次，**定下准则层不同准则的权重**后，进行计算得分。
## 1.2 求解步骤

### 1.2.1 确认目标层，准则层与方案层。

准则层：通过哪些指标进行比较；
方案层：实现目标的方案。

### 1.2.2 一致性检验

构建判断矩阵：
$$
a_{ij}=\frac{i准则的重要程度}{j准则的重要程度}
$$
对于具体的数据，例如价格，所有逻辑都是融洽的，不会存在违反逻辑的情况，为一致性矩阵。
例如，iPhone 1 的价格是1000元，iPhone 2 的价格是2000元，iPhone 3 的价格是3000元，就有如下矩阵：

|         | iPhone1 | iPhone2 | iPhone3 |
| ------- | ------- | ------- | ------- |
| iPhone1 | 1       | 1/2     | 1/3     |
| iPhone2 | 2       | 1       | 2/3     |
| iPhone3 | 3       | 3/2     | 1       |
一致性矩阵满足：
1. $a_{ii}=1$;
2. $a_{ij}=\frac{1}{a_{ji}}$; (**前两条满足是正互反矩阵**).
3. $a_{ij}=a_{ik}\times a_{kj}$. 也就是$a_{ij}=\frac{i准则的重要程度}{k准则的重要程度}\times \frac{k准则的重要程度}{j准则的重要程度}$

然而，一般情况下，重要程度一般是认为指定，不一定是完全符合第三条，所以需要通过某种方法评判是否满足一致性检验（近似满足第三条）。

当$A$为一致性矩阵时，由第三条得，任意两行互成比例，$rank(A)=1$，$tr(A)=n=\lambda_{max}$，其余特征值都为0。

>判断矩阵代表的是指标间的相对关系，不用正向化（可能需要取倒数）。

**通过计算一致性比例$CR$进行判断：**
$$
CR=\frac{CI}{RI} $\begin{cases} 0\;为一致性矩阵\\ <0.1 \;满足一致性检验\\ \ge0.1不满足一致性检验 \\end{cases}$
$$
其中，$(\lambda'_{max}是随机正互反矩阵的最大特征值的平均值，作为基准)$
$$
CI=\frac{\lambda_{max-n}}{n-1}\qquad RI=\frac{\lambda'_{max}-n}{n-1}
$$
$RI$查表得

| n   | 1   | 2   | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| --- | --- | --- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| RI  | 0   | 0   | 0.58 | 0.90 | 1.12 | 1.24 | 1.32 | 1.41 | 1.45 |
### 1.2.3 计算权重
如何求权重以及得分进行比较？
有三种办法，可以采用均值：
- **算术平均法**
	- 按列归一化后，按行求均值，就是对应的权重$$
			 w_i=\frac{1}{n}\sum_{j=1}^n \frac{a_{ij}}{\sum_{k=1}^n}(i=1,2,3,...,n)
		 $$
- **几何平均法**
	- 先按行相乘，开n次根号，最后按列求均值，就是对应权重。$$
	w_i=\frac{(\Pi_{j=1}^na_{ij})^{\frac{1}{n}}}{\sum_{k=1}^n(\Pi_{j=1}^{n}a_{kj})^{\frac{1}{n}}}(i=1,2,3,...,n)
	$$
- **特征值法**
	- 由最大特征值对应的特征向量，按列归一化就是权重.
### 1.2.4 最后计算得分
也可使用其他方法计算得分. 
也就是 $判断矩阵\times权重(列向量)$，即可得到得分。

\newpage

# 2 Topsis法.md

## 2.1 模型思想

$Topsis$法构建理想化的最优方案与最劣方案，无视方案的约束，挑选出每个指标中的最优值组成最优方案，挑选最劣值组成最劣方案。再对于每个方案计算距离最优方案与最劣方案的欧式距离，**计算评分**。

## 2.2 求解步骤

### 2.2.1 原始矩阵[[0.1 正向化|正向化]]

### 2.2.2 [[0.2 无量纲化|标准化]]，消除量纲
$$
z_{ij}=\frac{x_{ij}}{\sqrt{\sum_{i=1}^{n}x_{ij}^2}}
$$
### 2.2.3 找出理想最优与最劣解

$$
z_i^+=max\{ z_{1i},z_{2i},...,z_{ni}\}
$$
$$
z_i^-=min\{ z_{1i},z_{2i},...,z_{ni}\}
$$
### 2.2.4 指定权重$w_i$

这里可以使用层次分析法定权，或有熵权法，$Delphi$法，对数最小二乘法。

### 2.2.5 计算距离与权重
$D_i^+$是距离最优解距离，$D_i^-$是距离最劣解的距离，$S_i$是得分：
$$
\begin{align}
D_i^+&=\sqrt{\sum_{j=1}^m w_j(z_j^+-z_{ij})^2}\\
D_i^-&=\sqrt{\sum_{j=1}^m w_j(z_j^--z_{ij})^2}\\
S_i&=\frac{D_i^-}{D_i^++D_i^-}
\end{align}
$$
此时，得分的含义是，越大越好。

\newpage

# 3 熵权法.md

## 3.1 模型思想

通过衡量各指标在不同方案的信息熵，衡量其分散程度，分散性越大表示信息越多，信息熵越小，但信息效用值更高，赋予更高权重，**确定权重**。

## 3.2 求解步骤

考虑量化评价离散随机变量带有的信息量：对于某个变量，其出现概率越小，所带的信息量越大。
信息熵可以表达所有离散随机变量所导游的平均信息量，类似于期望。
有
$$
\begin{align}
信息量：I(x)&=-\ln p(x) \\ 
信息熵：H(x)&=-\sum_{i=1}^np(x)\ln p(x) \\ 

\end{align}
$$
### 3.2.1 原始矩阵[[0.1 正向化|正向化]]

### 3.2.2 矩阵[[0.2 无量纲化|标准化]]

### 3.2.3 矩阵[[0.1 归一化|比重归一化]]
$$
p_{ij}=\frac{z_{ij}}{\sum_{i=1}^nz_{ij}}
$$
### 3.2.4 计算

$n$是指标个数，$p_{ij}=\frac{z_{ij}}{\sum_{i=1}^n z_{ij}}$（归一化后）
$$
\begin{align}
归一化信息熵&： e_j=-\frac{1}{\ln n}\sum_{i=1}^{n}p_{ij}\ln p_{ij} \\
信息效用值&：d_j = 1-e_j \\ 
熵权&：W_j=\frac{d_j}{\sum_{j=1}{d_j}}
\end{align}
$$

\newpage

# 4 模糊综合评价法.md

## 4.1 模型思想

确立隶属函数，使得**界限模糊的概念**，能够被量化。

> [!NOTE] 辨析
> 相对于$Topsis$，$AHP$一层的评价，模糊综合评价关注指标的融合，使用行为指标，列为方案的写法较为方便。
> 假设评价一辆汽车：
> **TOPSIS、熵权法是在问：**
> **不同汽车在各项指标上的表现如何？**
> ```
>         油耗  动力  舒适
> 汽车A    8    90    85
> 汽车B    6    80    92
> 汽车C    7    95    80
> ```
> 每一行是一辆车，所以**行=方案**。
> **模糊综合评价是在问：**
>  **对于这一辆汽车，每个指标认为它属于"优、良、中、差"的程度是多少？**
> ```
>           优   良   中   差
> 油耗     0.7 0.3 0   0
> 动力     0.8 0.2 0   0
> 舒适     0.5 0.4 0.1 0
> ```
> 每一行是一个指标，所以**行=指标**。

## 4.2 求解步骤

### 4.2.1 确定隶属函数

通过隶属函数，将原始函数，转化为**隶属度**。
隶属度指其满足某一指标的程度$[0,1]$，也可以理解为对应指标的得分。
- 1.模糊统计法
	- 对于不同指标进行投票，例如对于成绩进行优秀良好合格进行投票。
- 2.**指派法，人为主观确定**
选择依据：不同指标之间的过渡情况是什么样的。

| **类型**         | **偏小型**                                                                                                                   | **中间型**                                                                                                                                                         | **偏大型**                                                                                                                      |
| -------------- | ------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| **矩阵型**        | $$\mu_A = \begin{cases} 1, & x \le a \\ 0, & x > a \end{cases}$$                                                          | $$\mu_A = \begin{cases} 1, & a \le x \le b \\ 0, & x < a \text{ 或 } x > b \end{cases}$$                                                                         | $$\mu_A = \begin{cases} 1, & x \ge a \\ 0, & x < a \end{cases}$$                                                             |
| **梯形型**        | $$\mu_A = \begin{cases} 1, & x \le a \\ \frac{b-x}{b-a}, & a \le x \le b \\ 0, & x > b \end{cases}$$                      | $$\mu_A = \begin{cases} \frac{x-a}{b-a}, & a \le x \le b \\ 1, & b \le x \le c \\ \frac{d-x}{d-c}, & c \le x \le d \\ 0, & x < a, x \ge d \end{cases}$$         | $$\mu_A = \begin{cases} 0, & x < a \\ \frac{x-a}{b-a}, & a \le x \le b \\ 1, & x > b \end{cases}$$                           |
| **$k$ 次抛物型**   | $$\mu_A = \begin{cases} 1, & x \le a \\ (\frac{b-x}{b-a})^k, & a \le x \le b \\ 0, & x > b \end{cases}$$                  | $$\mu_A = \begin{cases} (\frac{x-a}{b-a})^k, & a \le x \le b \\ 1, & b \le x \le c \\ (\frac{d-x}{d-c})^k, & c \le x \le d \\ 0, & x < a, x \ge d \end{cases}$$ | $$\mu_A = \begin{cases} 0, & x < a \\ (\frac{x-a}{b-a})^k, & a \le x \le b \\ 1, & x > b \end{cases}$$                       |
| **$\Gamma$ 型** | $$\mu_A = \begin{cases} 1, & x \le a \\ e^{-k(x-a)}, & x > a \end{cases}$$                                                | $$\mu_A = \begin{cases} e^{k(x-a)}, & x < a \\ 1, & a \le x \le b \\ e^{-k(x-b)}, & x > b \end{cases}$$                                                         | $$\mu_A = \begin{cases} 0, & x < a \\ 1 - e^{-k(x-a)}, & x \ge a \end{cases}$$                                               |
| **正态型**        | $$\mu_A = \begin{cases} 1, & x \le a \\ \exp\left\{-\left(\frac{x-a}{\sigma}\right)^2\right\}, & x > a \end{cases}$$      | $$\mu_A = \exp\left\{-\left(\frac{x-a}{\sigma}\right)^2\right\}$$                                                                                               | $$\mu_A = \begin{cases} 0, & x \le a \\ 1 - \exp\left\{-\left(\frac{x-a}{\sigma}\right)^2\right\}, & x > a \end{cases}$$     |
| **柯西型**        | $$\mu_A = \begin{cases} 1, & x \le a \\ \frac{1}{1+\alpha(x-a)^\beta}, & x > a \end{cases}$$<br>$(\alpha > 0, \beta > 0)$ | $$\mu_A = \frac{1}{1+\alpha(x-a)^\beta}$$<br>$(\alpha > 0, \beta \text{ 为正偶数})$                                                                                 | $$\mu_A = \begin{cases} 0, & x \le a \\ \frac{1}{1+\alpha(x-a)^{-\beta}}, & x > a \end{cases}$$<br>$(\alpha > 0, \beta > 0)$ |
- 3.其他方法，使用已经有的客观数据作为模糊集合的隶属度

### 4.2.2 确定指标权重

### 4.2.3 计算综合评价

权重向量 x 隶属度矩阵计算不同方案得分

## 4.3 多层次模糊综合评价

对于一个$n\times m \; (n个方案，m个指标)$的子模块，来说，运用依次模糊综合评价，可以降为$1\times m$的维度，此时可以并入父层级进行模糊综合评价。

\newpage

# 5 灰色关联分析.md

## 5.1 模型思想

灰色指部分信息已知，存在一定不确定性与模糊性。灰色关联分析是在灰色情况下，计算不同指标的关联度。

## 5.2 求解步骤

### 5.2.1 [[0.1 正向化]]，[[0.4 统一量纲]]

### 5.2.2 计算差值

将每一个指标的最大值取出，作为母序列$MAX(i)$。类似于$Topsis$，取出理想化的最优解作为比较。此时，若与理想最优解的关联度更高，意味着方案越优，得分越高。

计算所有子序列和母序列的差值：
$$
X_i(k)=|x_i(k)-MAX(k)|
$$
此时，得到了新的矩阵。

### 5.2.3 求关联系数

$\xi$是关联系数，$\rho \in[0,1]$为分辨系数一般取0.5
$$
\xi =\frac{a+\rho b}{X_{ij}+\rho b}
$$
其中，
$$
\begin{align}
a&=\min_i \min_k |x_i(k)-max(k)| \\ 
b&=\max_i \max_k |x_i(k)-max(k)|
\end{align}
$$
计算方法为，在差值矩阵中，先求出每个指标最小值，再求出所有指标最小值中的最小值，称为两级最小值，也就是$a$。
同理，在差值矩阵中，先求出每个指标最大值，再求出所有指标最大值中的最大值，称为两级最大值，也就是$b$。
此外，$\rho$越大，求出的关联系数之前差异越小。

计算完成后，得到新的关联系数矩阵。

### 5.2.4 求关联度
不同方案（非指标）求均值（或者加权求均值也行）：
$$
r_i=\frac{1}{n}\sum_{k=1}^n \xi_i(k)
$$
即可作为得分参与评价。

\newpage

# 6 线性规划.md

## 6.1 模型思想

$Linear \; Programming$是在一堆线性约束条件下，寻找一个使得线性目标函数达到最大值或最小的决策方案。%%多元函数极值%%

## 6.2 常见模型
### 6.2.1 01整数规划

| **维度**     | **背包问题 **                                         | **指派问题**                                                                                          |
| ---------- | ------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| **问题识别**   | **只有选择一个动作**，使得变量为一维。                             | **有选择与指派两个步骤**，变量为二维，例如$c_{ij}$表达是否把$i$指派给$j$。                                                    |
| **约束条件不同** | $$\sum w_i x_i \le W$$(选中物品的总重量不能超过背包最大承重 $W$)    | $$\sum_j x_{ij} = 1 \quad (\text{每人恰好做 1 个任务})$$ $$\sum_i x_{ij} = 1 \quad (\text{每任务恰好由 1 人做})$$ |
| **目标函数不同** | **通常为极大化收益**：$$\max \sum v_i x_i$$(求装入背包物品的总价值最大) | **通常为极小化成本/工时**： $$\min \sum_i \sum_j c_{ij} x_{ij}$$ (求所有匹配组合的总成本/总耗时最小)                         |
> 使用`milp`函数时，降维处理。求和手搓矩阵即可
### 6.2.2 蒙特卡洛模拟

暴力求解。让我们去掉高大上的奇怪名词。

## 6.3 求解步骤

### 6.3.1 一般线性规划

#### 6.3.1.1 条件转化

将题目表达转化为数学语言。
#### 6.3.1.2 转化为标准型

`python scipy.optimize.linprog`只接受标准型：
$$
\min_x c^Tx,s.t. $\begin{cases} Ax\le b \\ A \cdot x=b \\ lb \le x \le ub \end{cases}$
$$
其中，若要求$\max_x c^Tx$，可以同乘$-1$，转化为$\min_{-x} d^Tx$。
同理，若约束条件是$Ax \ge b$，也可以同乘$-1$转化为$Bx\le -b$。

#### 6.3.1.3求解

**导入**：
```python
from scipy.optimize import linprog
```

**函数原型**：
```python
scipy.optimize.linprog(
    c,
    A_ub=None,
    b_ub=None,
    A_eq=None,
    b_eq=None,
    bounds=(0, None),
    method='highs',
    callback=None,
    options=None,
    x0=None,
    integrality=None
)
```

其中，

| 参数            | 含义                                    |
| ------------- | ------------------------------------- |
| `c`           | 目标函数系数                                |
| `A_ub`        | 不等式约束系数矩阵                             |
| `b_ub`        | 不等式约束右端向量                             |
| `A_eq`        | 等式约束系数矩阵                              |
| `b_eq`        | 等式约束右端向量                              |
| `bounds`      | 决策变量上下界，$+\infty$为`None`（或使用`np.inf`） |
| `method`      | 求解算法，推荐 `'highs'`                     |
| `x0`          | 初始值（部分算法支持）                           |
| `integrality` | 整数规划约束（HiGHS支持）                       |
| `options`     | 求解器参数                                 |
| `callback`    | 每次迭代调用的回调函数                           |
可以用`*.x`取出最小处的点，`*.fun`取出最小值。

**返回值**：
返回一个 `OptimizeResult` 对象，常用属性：
- `x`：最优解（决策变量取值的一维数组）；
- `fun`：最优目标函数值（标量）；
- `success`：是否求解成功（布尔）；
- `message`：求解器状态说明。

### 6.3.2 线性整数规划

将一般线性规划的点，取整，观察是否满足约束条件。若满足则有解

**导入**：
```python
from scipy.optimize import milp, LinearConstraint
import numpy as np
```

使用

**函数原型**：
``` python
scipy.optimize.milp(
    c,
    *,
    integrality=None,
    bounds=None,
    constraints=None,
    options=None
)
```

| 参数            | 作用          |
| ------------- | ----------- |
| `c`           | 目标函数系数      |
| `integrality` | 指定哪些变量必须为整数 |
| `bounds`      | 决策变量上下界     |
| `constraints` | 线性约束        |
| `options`     | 求解器参数       |

|`integrality`|含义|变量取值|
|---|---|---|
|`0`|连续变量（Continuous）|任意实数（受 `bounds` 限制）|
|`1`|整数变量（Integer）|任意整数（受 `bounds` 限制）|
|`2`|半连续变量（Semi-continuous）|(0) 或区间 ([lb,ub]) 内的任意实数|
|`3`|半整数变量（Semi-integer）|(0) 或区间 ([lb,ub]) 内的任意整数|
其中，`constraints`结构为：

**函数原型**：
``` python
LinearConstraint(A, lb, ub, keep_feasible=False)
```

例如，
$$

$\begin{cases}  
x_1+x_2\ge4\\  
2x_1+x_2\le6\\
x_1-x_2=1  
\end{cases}$  

$$
写成

```python
A = np.array([
    [1, 1],
    [2, 1],
    [1,-1]
])
lb = np.array([
    4,
    -np.inf,
    1
])
ub = np.array([
    np.inf,
    6,
    1
])
constraint = LinearConstraint(A, lb, ub)
```

**返回值**：
- `milp` 返回一个 `OptimizeResult` 对象，常用属性：
  - `x`：最优解（决策变量取值的一维数组，整数变量取整数值）；
  - `fun`：最优目标函数值（标量）；
  - `success`：是否求解成功（布尔）；
  - `message`：求解器状态说明。
- `LinearConstraint(A, lb, ub)` 返回一个约束对象，供 `milp(..., constraints=...)` 使用，本身不返回值。


\newpage

# 7 非线性规划.md

## 7.1 模型思想

约束条件/目标函数存在非线性表达式时，寻找一个使得线性目标函数达到最大值或最小的决策方案。

## 7.2 求解步骤

### 7.2.1 条件转化

将题目表达转化为数学语言。
### 7.2.2 计算
`python scipy.optimize.minimize`可以传入任意非线性规划

**导入**：
```python
from scipy.optimize import minimize
```

**函数原型**：
``` python
scipy.optimize.minimize(
    fun,
    x0,
    args=(),
    method=None,
    jac=None,
    hess=None,
    hessp=None,
    bounds=None,
    constraints=(),
    tol=None,
    callback=None,
    options=None
)
```

| 参数            | 含义             |
| ------------- | -------------- |
| `fun`         | 目标函数，返回一个标量    |
| `x0`          | 初始点（一维数组）      |
| `args`        | 传递给目标函数的额外参数   |
| `method`      | 求解算法           |
| `jac`         | 目标函数梯度（可选）     |
| `hess`        | Hessian 矩阵（可选） |
| `hessp`       | Hessian 与向量乘积  |
| `bounds`      | 变量上下界          |
| `constraints` | 等式、不等式约束       |
| `tol`         | 收敛精度           |
| `callback`    | 每次迭代调用函数       |
| `options`     | 算法参数           |
**返回值**：
返回一个 `OptimizeResult` 对象，常用属性：
- `x`：最优解（决策变量取值的一维数组）；
- `fun`：最优目标函数值（标量）；
- `success`：是否求解成功（布尔）；
- `message`：求解器状态说明。

`constraints`:

|type|含义|数学形式|
|---|---|---|
|`"eq"`|等式约束|(g(x)=0)|
|`"ineq"`|不等式约束|(g(x)\ge0)|

`method`:

|method|边界|等式|不等式|适用场景|
|:-:|:-:|:-:|:-:|---|
|`COBYLA`|❌|❌|✅|无导数、小规模|
|`COBYQA`|✅|✅|✅|无导数、高精度|
|`SLSQP`|✅|✅|✅|一般非线性规划（最常用）|
|`trust-constr`|✅|✅|✅|大规模、复杂约束|

**示例：**
求解
$$
$\begin{array}{ll}
\min & x^2+y^2\\
\text{s.t.} &
$\begin{cases}
x+y\ge1,\\
x\ge0,\\
y\ge0.
\end{cases}$
\end{array}$
$$​

``` python

from scipy.optimize import minimize
def fun(x):
    return x[0]**2 + x[1]**2
cons = [
    {
        'type':'ineq',
        'fun':lambda x:x[0]+x[1]-1
    }
]
bounds=[
    (0,None),
    (0,None)
]
x0=[0.5,0.5]
res=minimize(fun,
             x0,
             method='SLSQP',
             bounds=bounds,
             constraints=cons)
```

\newpage

# 8 图论.md

## 8.1 定义

对于平面上的若干点, 把这些点用曲线或直线连接起来,不考虑点的位置与连线的曲直长短,这样形成的关系结构就是图。



## 8.2 图的分类
图又分为有向图和无向图。

## 8.3 图的表示方法
### 8.3.1 数学方法

一个图可以用数学语言表述为$G(V(G),E(g))$，$V(vector)$代表图的定点集合，$E(edge)$代表图的边集。

下面是一个有向图的直观例子，含 6 个顶点（$0-5$）与 8 条有向边（$e_1-e_8$）：



顶点集与边集可记为：

- 顶点集 $V = \{0, 1, 2, 3, 4, 5\}$
- 边集 $E = \{e_1, e_2, e_3, e_4, e_5, e_6, e_7, e_8\}$

### 8.3.2 计算机方法

1. 邻接矩阵

若图有`m`个点，对于二维数组`array[m][m]`，`array[i][j]`存储从`i`到`j`的边权`w`。
若未相连`np.inf`表示，`array[i][i]`用`0`表示。

若是无向图，其邻接矩阵是对称矩阵，`array[i][j]==array[j][i]`。

\newpage

# 9 最短路算法.md

## 9.1 定义

在带权图中，从给定起点$s$到终点$t$的所有可行路径中，**边权值之和最小**的一条路径，称为最短路。
## 9.2 求解
### 9.2.1 整数规划

设决策变量为$x_{ij}$，含义为：$\begin{cases} 1,从i点到j点在最短路上 \\ 0,从i点到j点不在最短路上\end{cases}$。
目标函数为$\min \sum_{(i,j) \in V}w_{ij}x_{ij}$。

约束条件如何转化？
出度：对于一个节点，有多少条边从他发散出去。
入度：对于一个节点，有多少条边进入他。

对于不是回路的情况来说：
$$
\begin{aligned}
$\begin{cases} 
起点s入度为0 \\ \\
终点t出度为0 \\ \\
中间节点k和终点t入度为1 \\ \\
中间节点k和起点s出度为1
\end{cases}$
\Rightarrow
$\begin{cases} 
\sum_{i,(i,s) \in E}^N x(i,s)=0 \\ \\
\sum_{i,(t,i) \in E}^N x(t,i)=0 \\ \\
\sum_{i,i \ne k,k \ne s ,(i, k)\in E }^Nx(i,k)=1 \\ \\
\sum_{i,j \ne k,k \ne t ,(k, i)\in E }^Nx(k,i)=1 
\end{cases}$
\end{aligned}
$$
也就是
$$
$\begin{cases}  
\displaystyle\sum_{i,i \ne s, (i,s)\in E}x_{is}=0,\\
\displaystyle\sum_{i,i \ne t, (t,j)\in E}x_{tj}=0,\\
\displaystyle\sum_{i,i \ne k, (i,k)\in E}x_{ik}=1,\qquad \forall k\in V(最短路径上的点)\setminus{s},\\
\displaystyle\sum_{i,i \ne k, (k,i)\in E}x_{ki}=1,\qquad \forall k\in V(最短路径上的点)\setminus{t}.  
\end{cases}$  
$$

继续简洁，流平衡约束，用出度减去入度：

当为初始节点时，出度减去入度为1；
终点出度减入度为0；
中间节点出度等于入度。
$$
s.t.$\begin{cases}
\sum_i x_{ki}-\sum_i x_{ik}=\begin{cases}1,k=s \\
-1, k=t \\ 
0,k\ne s,t
\end{cases}$\;, \\
x_{ij}\in\{0,1\}.
\end{cases}
$$
### 9.2.2 蒙特卡洛

暴力求解
### 9.2.3 $Dijkstra$算法

$Dijkstra$ 算法采用贪心策略，每一步都选择当前未确定节点中距起点最短（累计距离最小）的节点，并利用该节点更新其邻接节点的最短距离。
> $Dijkstra$ 算法无法处理负权重的最短路径。

### 9.2.4 $Floyd$算法

对于有负权重的最短路径问题，可以用$Floyd$算法。

### 9.2.5 调用函数算法

POV：当你学的是数学建模而不是computer sciense   bybike：
**导入**：
```python
from scipy.sparse.csgraph import shortest_path
```

**函数原型**：
```python
scipy.sparse.csgraph.shortest_path(
    csgraph,
    method='auto',
    directed=True,
    return_predecessors=False,
    unweighted=False,
    overwrite=False,
    indices=None
)

```

其中：

| 参数                    | 说明                                                                                         |
| --------------------- | ------------------------------------------------------------------------------------------ |
| `csgraph`             | 图的邻接矩阵，可以是 NumPy 数组或 SciPy 稀疏矩阵。元素表示边权，不连通一般用 `np.inf` 表示。                                 |
| `method`              | 求解算法。`'D'`：Dijkstra；`'BF'`：Bellman-Ford；`'FW'`：Floyd-Warshall；`'J'`：Johnson；`'auto'`：自动选择。 |
| `directed`            | 是否将图视为有向图。`True` 表示有向图，`False` 表示无向图。                                                      |
| `return_predecessors` | 是否返回前驱矩阵。若为 `True`，函数返回 `(dist_matrix, predecessors)`，可用于恢复最短路径。                           |
| `unweighted`          | 是否忽略边权。当设为 `True` 时，所有边权均视为 1，相当于在无权图上求最短路径（采用 BFS 思想）。                                    |
| `overwrite`           | 是否允许覆盖输入矩阵以节省内存，仅部分算法（如 Floyd）可能使用，一般保持默认即可。                                               |
| `indices`             | 指定起点。`None` 表示计算所有节点对之间的最短路径；整数表示单源最短路径；列表表示多个源点到所有节点的最短路径。                                |
`method`:

| 取值       | 算法             | 是否支持负权 | 典型应用                            |
| -------- | -------------- | ------ | ------------------------------- |
| `'auto'` | 自动选择           | ✔      | 根据图的特点自动选择合适算法。                 |
| `'D'`    | Dijkstra       | ✘      | 非负权图的单源或多源最短路径。                 |
| `'BF'`   | Bellman-Ford   | ✔      | 存在负权边但无负权环。                     |
| `'FW'`   | Floyd-Warshall | ✔      | 所有节点对最短路径，适用于规模较小或较稠密的图。        |
| `'J'`    | Johnson        | ✔      | 稀疏图的所有节点对最短路径，允许存在负权边（但不能有负权环）。 |
**返回值**：
当`return_predecessors`为`False`时，返回二维数组，值`res[i][j]`代表从i到j点的最短路径长度。

当`return_predecessors`为`True`时，返回元组。
1. `res[0]`：最短距离数组。`res[i][j]`代表从i到j点的最短路径长度。
- **类型与形状**：一维 NumPy 浮点型数组，长度为 $N$（节点数，代码中为 38）。
- 如果未指定 `indices` 参数，它会返回一个 $N \times N$ 的二维矩阵；若指定了$n$个参数，则只返回$n\times N$维数组。
- **特殊值**：如果节点 `i` 不可达，值为 `np.inf`（9999）。

2. `res[1]`：前驱节点数组。`res[1][i]` 表示从起点到达节点 `i` 的最短路径上，节点 `i` 的**前一个节点（前驱节点）的索引**。
- **特殊值**：
    - 起点本身的前驱节点值为 `-9999`（系统默认的无前驱标志）。
    - 无法到达的节点，前驱节点值通常为 `-9999`。

\newpage

# 10 网络最大流.md

## 10.1 定义

### 10.1.1 流量图

设有向图$D=(V,A,C)$，$V$是点的集合，$A$是边的集合，$C$是容量的集合。

通过弧$(V_i,V_j)$的流的数量称为流量，记作$x_{ij}$。$C_{ij}(\ge 0)$称为容量（流量的上限）。
所有弧上流量的集合$\{ x_{ij} \}$称为网络$D$的一个流。



其中，发点$V_s$是仅有出度的点，入点$V_t$是仅有入度的点，中间点是$V\setminus 发点与入点$。

标注了流量与容量的图称为流量图。

### 10.1.2 可行流

满足以下条件的是可行流：
1. 容量条件：$0\le x_{ij} \le C_{ij}$
2. 平衡条件：发点的净输出量 = 收点的净输入量，中间点的输入量 = 中间点的输出量。
是研究问题的前提。

### 10.1.2 增广链

增广链又称增流链，是一条从源点到汇点、且每条弧剩余容量均大于0的路径。沿该路径可以整体增加流量，因此称为增广链。

可以通过$(节点，边，节点)$的方法表示一条链。例如上图的$(V_i,(V_i,V_j),V_j)$。注意边的方向要和实际有向图方向一样。

若$(V_i,V_j)$的方向也是$V_s$到$V_t$的方向，称为前向弧，反之称为反向弧。

如何寻找增广链？前向弧流量越大越好，反向弧流量越小越好。计算是否为增广链时，类似于$KCL$，节点净出入流量守恒作为约束。

### 10.1.3 最大流

最大流是满足所有约束且总流量最大的可行流。

所有弧上流量的集合$\{ x_{ij} \}$称为网络$D$的一个流：当对于此时的$\{x_{ij}\}$，没有增广链时，称此时的$\{ x_{ij}\}$为最大流。即没有增广链⇔已经达到最大流。

## 10.2 求解

如何求最大流？$Ford Fulkerson$算法：

标号：若有弧$(V_i,V_j)$，那么给$V_j$标号$(+/-V_i,\Delta_j)$，+-分别指示前向弧/反向弧。
前向弧：$\Delta_j=\min\{ C_{ij}-x_{ij}, \Delta_i \}$表示$j$节点当前链条能优化的最大增量（木桶效应取最小值）
负向弧：$\Delta_j=\min\{ x_{ij}, \Delta_i \}$ （负向弧要考虑减少的最大量）
特殊的，出发点为$(0,+\infty)$。

每一次循环：
- 寻找是否有可以优化的弧：$x_{ij}<C_{ij}$，若有，计算$\Delta_j$并进入下一个节点。
- 若没有可以优化的弧，且当前点不是$V_t$，说明没有增广链了，此时的流是最大流。
- 若到达了$V_t$，说明找到了增广链，取所有$\Delta_i$的最小值，作为在当前链条上每一正向弧增量，负向弧减少量。
$continue...$

**导入**：
```python
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import maximum_flow
```

**函数原型**：
```python
scipy.sparse.csgraph.maximum_flow(
    csgraph,
    source,
    sink,
    *,
    method='dinic'
)
```

| 参数        | 类型            | 说明                          |
| --------- | ------------- | --------------------------- |
| `csgraph` | sparse matrix | 网络容量矩阵，必须要用`csr_matrix()`转换 |
| `source`  | int           | 源点编号                        |
| `sink`    | int           | 汇点编号                        |
| `method`  | {'dinic'}     | 求解算法，目前仅支持 Dinic 算法         |

**返回值**：
返回一个 `MaximumFlowResult` 对象。

|属性|类型|说明|
|---|---|---|
|`flow_value`|int|最大流值。|
|`flow`|ndarray|与容量矩阵同维度的流量矩阵，第 `(i,j)` 个元素表示边 $(i,j)$ 的实际流量。|
**注意**：
- 节点编号从 **0** 开始。
- 容量矩阵中的元素必须为**非负整数**，负容量是不允许的。

\newpage

# 11 最小费用最大流.md

## 10.1 定义

每条路线最大允许的容量和通过该弧的费用分别为$c_{ij}与w_{ij}$。



则可行流的费用为$\sum_{(v_i, v_j)\in A}w_{ij}x_{ij}$。$A$为弧集，$x_{ij}$为实际流量。

## 10.2 求解

最小费用：将费用作为边权，求$V_s$到$V_t$最短路径。

对于每一条弧，存在两种基本操作：**增加流量**和**减少流量**。增加流量对应于沿原始弧增广，减少流量对应于沿反向弧增广。
当$x_{ij}=0$ 时，仅允许增加流量，因此只有正向弧存在；
当 $x_{ij}=w_{ij}$ 时，仅允许减少流量，因此只有反向弧存在；
其余情况下，正向弧与反向弧同时存在。

每一次循环：
- 在当前残量网络中寻找源点到汇点的最小费用增广链条
- 计算该最短路上的最大增量并应用
- 根据增加后的流量，修改每一个弧，使得满足上述条件
- 找不到增广链时，取得最大流
$continue...$

**导入**：
```python
import networkx as nx
```

**函数原型**：
```python
networkx.max_flow_min_cost(G, s, t, capacity='capacity', weight='weight')
```

| 参数         | 类型               | 说明                     |
| ---------- | ---------------- | ---------------------- |
| `G`        | `NetworkX graph` | 有向图 (`DiGraph`)        |
| `s`        | Node             | 源点                     |
| `t`        | Node             | 汇点                     |
| `capacity` | str              | 容量属性名称，默认 `"capacity"` |
| `weight`   | str              | 单位费用属性名称，默认 `"weight"` |
其中，`NetworkX graph` 这样创建：
```python
G = nx.DiGraph()
G.add_edge(
    u,
    v,
    capacity=10,
    weight=5
)
```

**返回值**：
字典，`res[i][j]`表示`i`到`j`实际流量

**总费用**：
```python
nx.cost_of_flow(G, res)
```


\newpage

# 12 旅行商问题.md

## 12.1 定义

旅行商问题：给定一系列城市和每对城市之间的距离，求解**访问每座城市恰好一次并返回起始城市**的最短回路。



该回路称为 **Hamilton 回路**（遍历所有顶点且不重复的回路）。

## 12.2 求解

### 12.2.1 01整数规划

设决策变量为$x_{ij}$，含义为：$\begin{cases} 1,从i点到j点在最短路上 \\ 0,从i点到j点不在最短路上\end{cases}$。
目标函数为$\min \sum_{(i,j) \in V}w_{ij}x_{ij}$。

$$
s.t. 
$\begin{cases} 
出度=1\\ \\
入度=1 \\ \\
- \\ \\
能够跑到所有点，边数=点数
\end{cases}$

\Rightarrow

$\begin{cases}
\sum_j^nx_{ij}=1 \\ \\ 
\sum_i^nx_{ij}=1 \\ \\ 
x_{ij} \in \{0,1\} \\ \\
\sum_{ij\in V}x_{ij}=|V|
\end{cases}$
$$

### 12.2.2 改良圈算法

一种启发式算法，通过不断"断开—重连"来优化初始回路。

给定初始 Hamilton 圈 $C = v_1v_2\cdots v_nv_1$，对于任意 $1 < i+1 < j < n$，检查能否通过删除边 $(v_i, v_{i+1})$ 和 $(v_j, v_{j+1})$ 并添加边 $(v_i, v_j)$ 和 $(v_{i+1}, v_{j+1})$ 来缩短总路程。

若满足：

$$
w(v_i, v_j) + w(v_{i+1}, v_{j+1}) < w(v_i, v_{i+1}) + w(v_j, v_{j+1})
$$

则将 $C$ 中 $v_{i+1}$ 到 $v_j$ 这一段**逆序**，得到新回路 $C'$，路长缩短。

**步骤**：
1. 任取一个初始 Hamilton 圈 $C_0$（如按顶点编号顺序）
2. 对 $i = 1, 2, \dots, n-2$，$j = i+1, \dots, n-1$ 遍历，满足条件则反转 $v_{i+1} \sim v_j$ 段
3. 一轮结束后若未发生任何交换，算法终止；否则回到第 2 步

**Python 实现**：

**函数原型**：
```python
improve_circle(dist)
```

| 参数 | 类型 | 说明 |
| --- | --- | --- |
| `dist` | `np.ndarray` | n×n 距离矩阵，`dist[i][j]` 为城市 i 到 j 的距离 |

**返回值**：`(route, cost)`

| 返回值 | 类型 | 说明 |
| --- | --- | --- |
| `route` | `list` | 最优回路，顶点顺序列表（不含结尾重复的起点） |
| `cost` | `float` | 回路总距离 |

```python
import numpy as np

def improve_circle(dist):
    n = len(dist)
    route = list(range(n)) + [0]
    improved = True

    while improved:
        improved = False
        for i in range(n - 2):
            for j in range(i + 2, n):
                delta = (dist[route[i]][route[j]] +
                         dist[route[i+1]][route[(j+1) % n]] -
                         dist[route[i]][route[i+1]] -
                         dist[route[j]][route[(j+1) % n]])
                if delta < -1e-9:
                    route[i+1:j+1] = reversed(route[i+1:j+1])
                    improved = True

    cost = sum(dist[route[k]][route[k+1]] for k in range(n))
    return route[:-1], cost
```


\newpage

# 13 插值算法.md

## 13.1 算法思想

若已经有离散的$n+1$个点，满足$f(x)=y$。但我们不清楚具体函数时，可以找到新的函数$\varphi(x)=y$，来研究问题。

设有$n+1$个不同的节点$(x_i, y_i)(i=0,1,2,...,n)$则存在唯一多项式：
$$
\varphi(x_i)=a_0+a_1x_i+a_2x_i^2+...+a_nx_i^n=y_i,(i=j=0,1,2,...,n)
$$

此时，有方程组：

$$
$\begin{cases}
a_0 + a_1 x_0 + a_2 x_0^2 + \cdots + a_n x_0^n = y_0 \\
a_0 + a_1 x_1 + a_2 x_1^2 + \cdots + a_n x_1^n = y_1 \\
\vdots \\
a_0 + a_1 x_n + a_2 x_n^2 + \cdots + a_n x_n^n = y_n
\end{cases}$
$$
也就是
$$
\begin{bmatrix}
1 & x_0 & x_0^2 & \cdots & x_0^n \\
1 & x_1 & x_1^2 & \cdots & x_1^n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x_n & x_n^2 & \cdots & x_n^n
\end{bmatrix}
\begin{bmatrix}
a_0 \\ a_1 \\ \vdots \\ a_n
\end{bmatrix}
=
\begin{bmatrix}
y_0 \\ y_1 \\ \vdots \\ y_n
\end{bmatrix}
$$

## 13.2 常用插值

### 13.2.1 分段线性插值法

将相邻的节点依次用直线连接起来，形成的一条折线就是分段线性插值函数，记作$I_n(x)$。
$$
I_n(x)=\sum_{i=0}^ny_il_i(x)
$$
其中，
$$
l_i(x)=$\begin{cases}
\frac{x-x_{i-1}}{x_i-x_{i-1}},x\in[x_{i-1},x_i], i \ne 0 ,\\
\frac{x-x_{i+1}}{x_i-x_{i+1}}, x\in[x_i, x_{i+1}], i \ne n,\\
0,其他
\end{cases}$
$$
$l_i(x_j)$满足$\begin{cases}1, i=j \\ 0, i \ne j \end{cases}\;$。

### 13.2.2 拉格朗日插值法

拉格朗日插值法的基函数$l_i(x)$为：

$$
\begin{aligned}
l_i(x) &= \prod_{\substack{j=0 \\ j \ne i}}^{n} \frac{x - x_j}{x_i - x_j} \\
l_i(x) &= \frac{(x - x_0)(x - x_1)\cdots(x - x_{i-1})(x - x_{i+1})\cdots(x - x_n)}{(x_i - x_0)(x_i - x_1)\cdots(x_i - x_{i-1})(x_i - x_{i+1})\cdots(x_i - x_n)}
\end{aligned}
$$

满足 $l_i(x_j) = $\begin{cases}1, & i=j \\ 0, & i \ne j\end{cases}$\;$。
拉格朗日插值函数为：

$$
L_n(x) = \sum_{i=0}^{n} y_i \, l_i(x)
$$

### 13.2.3 牛顿插值法

定义一阶差商：
$$
f[x_i, x_j] = \frac{f(x_j) - f(x_i)}{x_j - x_i}
$$

二阶差商：
$$
f[x_i, x_j, x_k] = \frac{f[x_j, x_k] - f[x_i, x_j]}{x_k - x_i}
$$

$n$ 阶差商依此类推。

牛顿插值多项式为

$$
\begin{aligned}
N_n(x) = &f[x_0] \\
&+ f[x_0, x_1](x - x_0) \\
&+ f[x_0, x_1, x_2](x - x_0)(x - x_1) \\
&+ \cdots \\
&+ f[x_0, x_1, \dots, x_n](x - x_0)(x - x_1)\cdots(x - x_{n-1})
\end{aligned}
$$

### 13.2.4 埃尔米特插值法

分段线性插值不光滑，$Hermite$插值在节点处不仅匹配函数值，还匹配导数值，保证$1$阶导数连续。

在每个子区间 $[x_i, x_{i+1}]$ 上用三次多项式 $H_i(x)$，满足四个条件：

$$
$\begin{cases}
H_i(x_i) = y_i, \quad H_i'(x_i) = y_i' \\
H_i(x_{i+1}) = y_{i+1}, \quad H_i'(x_{i+1}) = y_{i+1}'
\end{cases}$
$$

令 $h = x_{i+1} - x_i$，$t = \dfrac{x - x_i}{h}$，基函数为：

$$
\begin{aligned}
\alpha_i(x) &= (1 + 2t)(1 - t)^2 \\
\alpha_{i+1}(x) &= (3 - 2t)t^2 \\
\beta_i(x) &= t(1 - t)^2 h \\
\beta_{i+1}(x) &= (t - 1)t^2 h
\end{aligned}
$$

插值多项式为：

$$
H_i(x) = y_i \,\alpha_i(x) + y_{i+1} \,\alpha_{i+1}(x) + y_i' \,\beta_i(x) + y_{i+1}' \,\beta_{i+1}(x)
$$

其中基函数满足：

| 基函数 | 在 $x_i$ 处的值 | 在 $x_i$ 处的导数值 | 在 $x_{i+1}$ 处的值 | 在 $x_{i+1}$ 处的导数值 |
| --- | --- | --- | --- | --- |
| $\alpha_i$ | 1 | 0 | 0 | 0 |
| $\alpha_{i+1}$ | 0 | 0 | 1 | 0 |
| $\beta_i$ | 0 | 1 | 0 | 0 |
| $\beta_{i+1}$ | 0 | 0 | 0 | 1 |

### 13.2.5 样条插值法

样条插值在每段用低次多项式，并在节点处保证一定的光滑性，保证$2$阶导数连续。避免高次多项式的 Runge 振荡。

满足条件：
1. $S_i(x_i) = y_i,\ S_i(x_{i+1}) = y_{i+1}$
2. $S_i'(x_{i+1}) = S_{i+1}'(x_{i+1})$
3. $S_i''(x_{i+1}) = S_{i+1}''(x_{i+1})$
4. 边界条件（三选一）：
   - 自然边界：$S_0''(x_0) = S_{n-1}''(x_n) = 0$
   - 固定边界：$S_0'(x_0) = A,\ S_{n-1}'(x_n) = B$
   - 周期边界：$S_0'(x_0) = S_{n-1}'(x_n),\ S_0''(x_0) = S_{n-1}''(x_n)$

## 13.3 求解

### 13.3.1 三次样条插值法

**导入**：
```python
from scipy.interpolate import CubicSpline
```

**函数原型**：
```python
CubicSpline(x, y, bc_type='not-a-knot', extrapolate=True)
```

| 参数 | 类型 | 说明 |
| --- | --- | --- |
| `x` | array | 插值节点（必须递增） |
| `y` | array | 节点处函数值 |
| `bc_type` | str / tuple | 边界条件 |

| `bc_type` | 含义 |
| --- | --- |
| `'not-a-knot'` | 非扭结边界（默认），前两段与后两段三阶导相等 |
| `'natural'` | 自然边界，两端二阶导为 0 |
| `'clamped'` | 固定边界，`bc_type=((1, dy0), (1, dyn))` |
| `'periodic'` | 周期边界 |

**返回值**：`CubicSpline` 对象，可像函数一样调用。

```python
cs = CubicSpline(x, y, bc_type='natural')
y_new = cs(x_new)
```

### 13.3.2 分段三次埃尔米特插值

**导入**：
```python
from scipy.interpolate import PchipInterpolator
```

**函数原型**：
```python
PchipInterpolator(x, y, axis=0, extrapolate=None)
```

| 参数 | 类型 | 说明 |
| --- | --- | --- |
| `x` | array | 插值节点（须单调递增） |
| `y` | array | 节点处函数值 |
| `extrapolate` | bool | 是否允许外推 |

**返回值**：`PchipInterpolator` 对象，可像函数一样调用。

```python
p = PchipInterpolator(x, y)
y_new = p(x_new)
```

### 13.3.3 高维插值

**导入**：
```python
from scipy.interpolate import griddata
```

**函数原型**：
```python
griddata(points, values, xi, method='linear', fill_value=nan)
```

| 参数 | 类型 | 说明 |
| --- | --- | --- |
| `points` | (n, D) array | n 个散点的 D 维坐标 |
| `values` | (n,) array | 各散点处的函数值 |
| `xi` | (m, D) array | 待插值点坐标 |
| `method` | str | `'linear'`（默认）\| `'nearest'` \| `'cubic'` |
| `fill_value` | float | 外推填充值 |

| method      | 算法                       | 原理                                                                       |
| ----------- | ------------------------ | ------------------------------------------------------------------------ |
| `'linear'`  | **Delaunay 三角剖分 + 线性插值** | 将散点剖成三角形，待插值点落在哪个三角形内，就用该三角形三个顶点的值做重心坐标线性加权                              |
| `'nearest'` | **Voronoi 图最近邻**         | 找到距离待插值点最近的已知散点，直接赋其值，结果分片常数                                             |
| `'cubic'**  | **Delaunay 三角剖分 + 三次插值** | 同样先三角剖分，但在每个三角形上拟合一个 **Clough-Tocher 分片三次多项式**（每个三角形 9 个自由度，保证 $C^1$ 连续） |

**返回值**：`(m,)` array，插值结果。

```python
# 二维散点插值
points = np.random.rand(50, 2)
values = np.sin(points[:, 0]) * np.cos(points[:, 1])
xi = np.random.rand(20, 2)

zi = griddata(points, values, xi, method='cubic')
```
