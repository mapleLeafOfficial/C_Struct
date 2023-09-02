#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define MAXSIZE 50
/*InitList初始化链表 ， 构造一个空的链表
 *Lenght 求表长 ， 返回线性表L的擦和你共度  ， 即L中的数据的个数
 *GetElem 按值查找 获得L中i位置的Elem的值
 *ListInsert 插入操作 ， 返回布尔值
 *ListDelete 删除节点 ， 返回删除的元素
 *ToString 将节点的元素变为字符串
 *Emply 判断是否为空
 *DestroyList 销毁当前链表*/
typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} LinearList;
LinearList linearList;

void initList() {
    // 开辟50个的内存空间
    linearList.data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    // 将长度设置为0
    linearList.length = 0;
}

int getLength() { return linearList.length; }

ElemType getElem(int index) {
    if (linearList.data == NULL) {
        err(1, "NuLL");
    } else if (linearList.length == MAXSIZE) {
        // 扩容

    } else {
        return linearList.data[index];
    }
}

bool addElem(int index, ElemType data) {
    int length = linearList.length;
    if (length == MAXSIZE) {
        // 扩容

    } else {
        if (length == 0){
            linearList.data[length] = data;
        }else{
        for (int i = length; i >= index; i--) {
            if (linearList.data[index] != NULL){
                int endIndex = i - 1;
                linearList.data[i] = linearList.data[endIndex];
            }else{
                break;
            }
        }
        linearList.data[index] = data;
        }
        linearList.length++;
        return true;
    }
    return false;
}
ElemType ListDelete(int index) {
    if (linearList.data == NULL){
        return 0;
    } else {
        if (index == linearList.length-1){
            linearList.length--;
            linearList.data[index] = 0;
        }else{
        for (int i = index; i <= linearList.length; ++i) {
            //向前移动删除指定索引
           linearList.data[i] = linearList.data[i+1];
        }
            linearList.length--;
        }
    }
}

void ToString() {
    int length = linearList.length;
    char string[length][200];
    for (int index = 0; index < length; index++) {
        sprintf(string[index], "%d", linearList.data[index]);
    }
    for (int i = 0; i < length; i++) {
        printf("%s\t", string[i]);
    }
}

bool Emply() {
    if (!linearList.length) {
        return true;
    } else {
        return false;
    }
}

int main() {
    initList();
    printf("%d\n",Emply());
    addElem(0, 1);
    addElem(1, 2);
    addElem(1, 3);
    ListDelete(2);
    ToString();
    printf("\n%d\n", getLength());
    printf("%d\n",Emply());
    return 0;
}
