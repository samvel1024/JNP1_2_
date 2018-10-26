#include "strset.h"
#include "strsetconst.h"

#include <assert.h>
#include <stdio.h>

int main() {
    unsigned long s1, s2, s3;

    s1 = strset_new();
    strset_insert(s1, "foo");


    strset_insert(s1, "bar");


    strset_insert(s1, "bar");

    strset_remove(s1, "foo");




    strset_delete(s1);
    strset_insert(s1, "whatever");



    s2 = strset_new();
    s3 = strset_new();
    strset_insert(s2, "Ania");
    strset_insert(s2, "Alek");
    strset_insert(s2, "Maria");
    strset_insert(s2, "Fiona");
    strset_insert(s3, "Ania");
    strset_insert(s3, "Maria");


    strset_remove(s2, "Alek");
    strset_remove(s2, "Fiona");
    strset_remove(s2, "Olek");

    strset_clear(s3);

    strset_clear(s2);

    strset_delete(s2);
    strset_delete(s3);



    strset_delete(strset42());
    strset_insert(strset42(), "66");

    strset_insert(strset42(), "24");
    strset_insert(strset42(), "42");


    strset_remove(strset42(), "42");

    strset_clear(strset42());





    return 0;
}
