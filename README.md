# BF
练习用简易brainfuck解释器
## 基础命令
BF_0_0.exe code.bf  
从code.bf内以文本模式读入源代码并以标准输出流输出  
## 命令行参数
### -30 -100 -300 -1000  
分别将cell数量指定为30、100、300、1000  
默认为-30  
### -left -middle  
分别将初始ptr位置设置为0位、cell数量/2-1位  
### -i ifilename  
将标准输入流修改为ifilename文件流  
### -o ofilename  
将标准输出流修改为ofilename文件流  
## 源代码特性
支持//样式注释  
即使[]中含有非bf符号，若代码允许则跳过  
未经过中文测试，请勿使用中文  
