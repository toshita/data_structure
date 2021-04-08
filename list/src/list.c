/**
 * list.c
 * 
 * Copyright (c) 2021 Toshita
 * This software is released under the MIT License, see LICENSE, see LICENSE.
 * This website content is released under the CC BY 4.0 License, see LICENSE.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * @brief 配列を初期化し、管理用の構造体のポインタを返す。
 * 
 * @return st_list* リスト管理構造体のポインタ
 */
st_list *init_list()
{
    st_list *pStList = (st_list *)malloc(sizeof(st_list));
    if (pStList == NULL)
    {
        return NULL;
    }

    pStList->pCurrent = NULL;
    pStList->pHead = NULL;
    pStList->size = 0;

    return pStList;
}

/**
 * @brief リストの指定した位置に要素を追加する。
 * 
 * @param head リストの先頭のポインタ
 * @param elm 追加する要素のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int add(st_list_element **head, st_list_element *elm, int iNum)
{
    st_list_element *pCur = *head; // 操作している要素
    st_list_element *prev = NULL;  // 前の要素
    int count = 0;

    // 追加する要素がNULLの場合
    if (elm == NULL)
    {
        return -1;
    }

    if (iNum == 0) // 先頭に要素を追加する場合
    {
        elm->next = *head;
        *head = elm;
        return 0;
    }
    else // 2番目以降に追加する場合
    {

        do
        {
            prev = pCur;
            pCur = pCur->next;
            count++;
        } while (pCur != NULL && count < iNum);

        // 要素を追加する
        elm->next = prev->next;
        prev->next = elm;
        return 0;
    }
}

/**
 * @brief リストの指定した位置に要素を追加する。
 * 
 * @param head リストの先頭のポインタ
 * @param elm 追加する要素のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int add_ex(st_list *pStList, st_list_element *elm, int iNum)
{
    if (pStList == NULL || pStList->size < iNum)
    {
        return -1;
    }
    if (add(&pStList->pHead, elm, iNum) == 0)
    {
        pStList->size++;
    }

    return 0;
}

/**
 * @brief 指定した番号の要素を削除する。
 * 
 * @param head リストの先頭のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int delete (st_list_element **head, int iNum)
{
    st_list_element *pCur = *head;
    st_list_element *prev = NULL;
    st_list_element *del = NULL;
    int i;

    // ヘッドがNULLの場合
    if (head == NULL || iNum < 0)
    {
        return -1;
    }

    // 最初の要素を消す場合
    if (iNum == 0)
    {
        del = (*head);
        *head = (*head)->next;
        free(del);
        return 0;
    }
    else
    {
        prev = (*head);
        pCur = (*head)->next;
        // 最後のリストを探す
        for (i = 1; i <= iNum && pCur != NULL; i++)
        {
            if (i == iNum)
            {
                // 要素を削除する
                del = pCur;
                prev->next = pCur->next;
                free(del);
                del = NULL;
                return 0;
            }
            prev = pCur;
            pCur = pCur->next;
        }
    }

    return 0;
}

/**
 * @brief 指定した番号の要素を削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_ex(st_list *pStList, int iNum)
{
    // 引数確認
    if (pStList == NULL || iNum < 0 || pStList->size <= iNum)
    {
        return -1;
    }

    // 要素を削除する
    if (delete (&pStList->pHead, iNum) == 0)
    {
        pStList->size--;
    }

    return 0;
}

/**
 * @brief リストの要素を全て削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_all(st_list *pStList)
{
    int i, count;
    if (pStList == NULL)
    {
        return -1;
    }

    // 最期の要素から削除する
    count = pStList->size;
    for (i = count - 1; i >= 0; i--)
    {
        if (delete (&pStList->pHead, i) == 0)
        {
            pStList->size--;
        }
        else
        {
            return -1;
        }
    }
    // st_list_element *head = (st_list_element *)malloc(sizeof(st_list_element));
    // pStList->pHead = head;

    return 0;
}

/**
 * @brief 管理用リストも含めて全体を削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ 
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_list(st_list **pStList)
{
    if (pStList == NULL)
    {
        return -1;
    }

    delete_all(*pStList);

    // 管理用の構造体を削除
    free(*pStList);
    *pStList = NULL;
    
    return 0;
}

/**
 * @brief 指定した要素を取得する。
 * 
 * @param head リストの先頭のポインタ
 * @param iNum 取得する位置（先頭を0とする） 
 * @return st_list_element* 要素のポインタ
 */
st_list_element *get(st_list_element *head, int iNum)
{
    int i;
    st_list_element *cur = head;

    // リストがNULLの場合
    if (cur == NULL)
    {
        return NULL;
    }

    // 指定された番号の要素を探す
    for (i = 0; i <= iNum && cur != NULL; i++)
    {
        if (i == iNum)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

/**
 * @brief 指定した要素を取得する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @param iNum 取得する位置（先頭を0とする） 
 * @return st_list_element*  要素のポインタ
 */
st_list_element *get_ex(st_list *pStList, int iNum)
{
    // 引数確認
    if (pStList == NULL || iNum < 0 || pStList->size <= iNum)
    {
        return NULL;
    }

    return get(pStList->pHead, iNum);
}

/**
 * @brief 要素のメモリ領域を作成する。
 * 
 * @param data 管理するデータ
 * @return st_element* 要素のポインタ
 */
st_list_element *make_data(int data){
    st_list_element *elm = (st_list_element *)malloc(sizeof(st_list_element));
    elm->data = data;

    return elm;
}

/**
 * @brief 先頭から順に要素の内容を標準出力に出力する。
 * 
 * @param head リストの先頭のポインタ
 */
void printListAll(st_list_element *head)
{
    printf("printListAll\n");

    if (head == NULL)
    {
        printf("list size = 0\n");
    }

    st_list_element *pCur = head;
    int i = 0;

    do
    {
        printf("[%2d]\n", i);
        printElement(pCur);
        if (pCur != NULL)
        {
            pCur = pCur->next;
        }
        i++;
    } while (pCur != NULL);
    printf("print end\n");
}

void printListAll_ex(st_list *pStList){
    // 引数確認
    if (pStList == NULL)
    {
        printf("pStList is NULL\n");
        return;
    }

    printListAll(pStList->pHead);
    return;
}

/**
 * @brief 指定した要素の内容を標準出力に出力する。
 * 
 * @param elm 表示する要素のポインタ
 */
void printElement(st_list_element *elm)
{
    printf("=============================\n");
    if (elm == NULL)
    {
        printf("empty!!\n");
    }
    else
    {
        printf("addr = %p\n", elm);
        printf("data = %d\n", elm->data);
        printf("next = %p\n", elm->next);
    }
    printf("-----------------------------\n");
}
