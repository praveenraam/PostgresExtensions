extern "C" {
    #include "postgres.h"
    #include "fmgr.h"

    PG_MODULE_MAGIC;
}

#include<cmath>

// #ifdef
// #endif

extern "C"{

    PG_FUNCTION_INFO_V1(calc_add);
    Datum calc_add(PG_FUNCTION_ARGS){
        int32 a = PG_GETARG_INT32(0);
        int32 b = PG_GETARG_INT32(1);

        PG_RETURN_INT32(a+b);
    }

    PG_FUNCTION_INFO_V1(calc_sub);
    Datum calc_sub(PG_FUNCTION_ARGS){
        int32 a = PG_GETARG_INT32(0);
        int32 b = PG_GETARG_INT32(1);

        PG_RETURN_INT32(a-b);
    }

    PG_FUNCTION_INFO_V1(calc_mul);
    Datum calc_mul(PG_FUNCTION_ARGS){
        int32 a = PG_GETARG_INT32(0);
        int32 b = PG_GETARG_INT32(1);

        PG_RETURN_INT32(a*b);
    }

    PG_FUNCTION_INFO_V1(calc_div);
    Datum calc_div(PG_FUNCTION_ARGS){
        int32 a = PG_GETARG_INT32(0);
        int32 b = PG_GETARG_INT32(1);

        if(b == 0){
            ereport(
                ERROR, (
                    errcode(ERRCODE_DIVISION_BY_ZERO), errmsg("division by zero")
                )
            );
        }

        PG_RETURN_INT32(a/b);
    }

    PG_FUNCTION_INFO_V1(calc_mod);
    Datum calc_mod(PG_FUNCTION_ARGS){

        int32 a = PG_GETARG_INT32(0);
        int32 b = PG_GETARG_INT32(1);

        if(b == 0){
            ereport(
                ERROR, (
                    errcode(ERRCODE_DIVISION_BY_ZERO), errmsg("modules by zero")
                )
            );
        }

        PG_RETURN_INT32(a%b);
    }

    PG_FUNCTION_INFO_V1(calc_pow);
    Datum calc_pow(PG_FUNCTION_ARGS){

        int32 base = PG_GETARG_INT32(0);
        int32 exp = PG_GETARG_INT32(1);

        if (exp < 0)
            ereport(ERROR,
                (errcode(ERRCODE_INVALID_PARAMETER_VALUE),
                 errmsg("exponent must be non-negative")));

        PG_RETURN_INT32(static_cast<int32>(std::pow(base,exp)));
    }
}