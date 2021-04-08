/**
 * main.c
 * 
 * Copyright (c) 2021 Toshita
 * This software is released under the MIT License, see LICENSE, see LICENSE.
 * This website content is released under the CC BY 4.0 License, see LICENSE.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * @brief 単方向リストの動作を確認するためのメイン関数。
 * 
 * @return int 
 */
int main()
{
    int result = 0, i;
    printf("データ構造：単方向リスト\n\n");
    st_list *pStList = init_list();

    printf("要素を追加する処理の確認\n");
    printf("1回目の要素追加\n");
    st_list_element *elm1 = make_data(10);
    result = add_ex(pStList, elm1, 0);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");

    printf("2回目の要素追加（最後）\n");
    st_list_element *elm2 = make_data(40);
    result = add_ex(pStList, elm2, 1);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");

    printf("3回目の要素追加（1番目）\n");
    st_list_element *elm3 = make_data(20);
    result = add_ex(pStList, elm3, 1);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");
    printf("\n\n\n");

    printf("4回目の要素追加（2番目）\n");
    st_list_element *elm4 = make_data(30);
    result = add_ex(pStList, elm4, 2);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");
    printf("\n\n\n");

    printf("5回目の要素追加（範囲外）\n");
    st_list_element *elm5 = make_data(50);
    result = add_ex(pStList, elm5, 5);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    free(elm5);
    printf("\n");
    printf("\n\n\n");

    // 要素を表示する
    printf("要素を取得する処理の確認\n");
    printf("print element\n");
    printf("1番目の要素を取得\n");
    printElement(get_ex(pStList, 0));
    printf("\n");
    printf("2番目の要素を取得\n");
    printElement(get_ex(pStList, 1));
    printf("\n");
    printf("3番目の要素を取得\n");
    printElement(get_ex(pStList, 2));
    printf("\n");
    printf("4番目の要素を取得\n");
    printElement(get_ex(pStList, 3));
    printf("\n\n\n");

    // 要素を指定した削除の確認
    printf("要素を削除する処理の確認\n");
    printf("範囲外の要素を指定して削除\n");
    result = delete_ex(pStList, 4);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");

    printf("\n\n最後の要素をして削除\n");
    result = delete_ex(pStList, 3);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");

    printf("\n\n0番目の要素を指定して削除\n");
    result = delete_ex(pStList, 0);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n");

    printf("\n\n1番目の要素を指定して削除\n");
    result = delete_ex(pStList, 1);
    printf("処理結果 : %d\n", result);
    printListAll(pStList->pHead);
    printf("\n\n\n");

    // リストの要素を全て空にする。
    printf("リスト要素を全て削除する処理の確認\n");
    printf("%d\n", pStList->size);
    for (i = pStList->size; i < 10; i++)
    {
        result = add_ex(pStList, make_data(i), i);
        printf(" %d:%d\n", i, result);
    }
    printListAll(pStList->pHead);
    printf("\n\nリストの要素を全て削除\n");  
    delete_all(pStList);
    printListAll(pStList->pHead);
    printf("\n\n\n");

    // リストの管理配列も含めてすべて削除する。
    // 要素を指定した削除の確認
    printf("リストの管理配列も含めて全てを削除する処理の確認\n");
    for (i = 0; i < 10; i++)
    {
        result = add_ex(pStList, make_data(i), i);
    }
    printListAll(pStList->pHead);
    printf("\n\nリストの管理配列を削除\n");
    delete_list(&pStList);
    printListAll_ex(pStList);
    printf("\n\n\n");

    return 0;
}