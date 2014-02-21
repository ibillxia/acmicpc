//m为学校数，n为学生数，k为学生填报的志愿数
//mq[i][0]为学校i计划招生数，mq[i][1]为学校实际招生数，  第155192号提交
//mq[i][2] ~ mq[i][mq[i][1]+1]为招收的学生的学号
//ng[i][0]为学生学号，ng[i][1]为学生总成绩，ng[i][2]为学生面试成绩，
//ng[i][2]后面的k个数据是填报的志愿

int m,n,k,mq[100][1000],ng[40000][8];

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
