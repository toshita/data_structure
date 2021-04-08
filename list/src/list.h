/**
 * list.h
 * 
 * Copyright (c) 2021 Toshita
 * This software is released under the MIT License, see LICENSE, see LICENSE.
 * This website content is released under the CC BY 4.0 License, see LICENSE.
 **/

#ifndef LIST_H
#define LIST_H

/**
 * @brief リストの要素
 * 
 */
typedef struct st_element
{
    int type;
    int data;
    struct st_element *next;
} st_list_element;

/**
 * @brief リストを管理する構造体
 * 
 */
typedef struct st_list
{
    st_list_element *pHead;
    st_list_element *pCurrent;
    int size;
} st_list;

/**
 * @brief 配列を初期化し、管理用の構造体のポインタを返す。
 * 
 * @return st_list* リスト管理構造体のポインタ
 */
st_list *init_list();

/**
 * @brief リストの指定した位置に要素を追加する。
 * 
 * @param head リストの先頭のポインタ
 * @param elm 追加する要素のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int add(st_list_element **head, st_list_element *elm, int iNum);

/**
 * @brief 要素を最後に追加する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @param elm 追加する要素のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int add_ex(st_list *pStList, st_list_element *elm, int iNum);

/**
 * @brief 指定した番号の要素を削除する。
 * 
 * @param head リストの先頭のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了
 */
int delete (st_list_element **head, int iNum);

/**
 * @brief 指定した番号の要素を削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @param iNum 追加する位置（先頭を0とする）
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_ex(st_list *pStList, int iNum);

/**
 * @brief リストの要素を全て削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_all(st_list *pStList);

/**
 * @brief 管理用リストも含めて全体を削除する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @return int 0:正常終了, -1:異常終了 
 */
int delete_list(st_list **pStList);

/**
 * @brief 指定した要素を取得する。
 * 
 * @param head リストの先頭のポインタ
 * @param iNum 取得する位置（先頭を0とする） 
 * @return st_list_element* 要素のポインタ
 */
st_list_element *get(st_list_element *head, int iNum);

/**
 * @brief 指定した要素を取得する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 * @param iNum 取得する位置（先頭を0とする） 
 * @return st_list_element*  要素のポインタ
 */
st_list_element *get_ex(st_list *pStList, int iNum);

/**
 * @brief 要素のメモリ領域を作成する。
 * 
 * @param data 管理するデータ
 * @return st_element* 要素のポインタ
 */
st_list_element *make_data(int data);

/**
 * @brief 先頭から順に要素の内容を標準出力に出力する。
 * 
 * @param head リストの先頭のポインタ
 */
void printListAll(st_list_element *head);

/**
 * @brief 先頭から順に要素の内容を標準出力に出力する。
 * 
 * @param pStList 操作対象のリストの管理構造体のポインタ
 */
void printListAll_ex(st_list *pStList);

/**
 * @brief 指定した要素の内容を標準出力に出力する。
 * 
 * @param elm 表示する要素のポインタ
 */
void printElement(st_list_element *elm);

#endif