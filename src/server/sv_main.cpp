#include <cstdio>
#include "qcvm/qcvm.h"

void print()
{
	int i;

	for (i = 0; i < qc_argc; i++)
	{
		printf("%s", QC_GET_STRING(QC_OFS_PARM0 + i * 3));
	}
}

qc_export_t export_thingy = 
{
    "example",
    "test",
    print,
    QC_TYPE_VOID,
    {{"str", QC_TYPE_FLOAT},
    {"...", QC_TYPE_VARGS}},
    2
};

int main(int argc, char const *argv[])
{
    qc_load("progs.dat");

    qc_add_export(&export_thingy);

    qc_execute((qc_function_get("main")));

    return 0;
}
