void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->JOYSICK,2,retain)
  __INIT_VAR(data__->VALAV,3,retain)
  __INIT_VAR(data__->VALRET,1,retain)
  __INIT_VAR(data__->BOBINAA,0,retain)
  __INIT_VAR(data__->BOBINAB,0,retain)
  __INIT_VAR(data__->BOBINAC,0,retain)
  __INIT_VAR(data__->BOBINAD,0,retain)
  __INIT_VAR(data__->RELOJ,__time_to_timespec(1, 200, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RELOJA,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RELOJB,__time_to_timespec(1, 200, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RELOJC,__time_to_timespec(1, 400, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RELOJD,__time_to_timespec(1, 600, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CLOCK,__time_to_timespec(1, 0, 4, 0, 0, 0),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TON_init__(&data__->TON2,retain);
  TP_init__(&data__->TP2,retain);
  TON_init__(&data__->TON3,retain);
  TP_init__(&data__->TP3,retain);
  TON_init__(&data__->TON4,retain);
  TP_init__(&data__->TP4,retain);
  __INIT_VAR(data__->GT17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LE16_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON4.,IN,,!(__GET_VAR(data__->BOBINAA,)));
  __SET_VAR(data__->TON4.,PT,,__GET_VAR(data__->CLOCK,));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->TP4.,IN,,__GET_VAR(data__->TON4.Q,));
  __SET_VAR(data__->TP4.,PT,,__GET_VAR(data__->CLOCK,));
  TP_body__(&data__->TP4);
  __SET_VAR(data__->,BOBINAA,,__GET_VAR(data__->TP4.Q,));
  __SET_VAR(data__->,GT17_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->JOYSICK,),
    (INT)__GET_VAR(data__->VALAV,)));
  __SET_VAR(data__->,AND45_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP4.Q,),
    (BOOL)__GET_VAR(data__->GT17_OUT,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->AND45_OUT,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->RELOJA,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TP0.,PT,,__GET_VAR(data__->RELOJ,));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,BOBINAA,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->AND45_OUT,));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->RELOJB,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TP1.,PT,,__GET_VAR(data__->RELOJ,));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,BOBINAB,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->AND45_OUT,));
  __SET_VAR(data__->TON2.,PT,,__GET_VAR(data__->RELOJC,));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->TP2.,PT,,__GET_VAR(data__->RELOJ,));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,BOBINAC,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->AND45_OUT,));
  __SET_VAR(data__->TON3.,PT,,__GET_VAR(data__->RELOJD,));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->TP3.,IN,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->TP3.,PT,,__GET_VAR(data__->RELOJ,));
  TP_body__(&data__->TP3);
  __SET_VAR(data__->,BOBINAD,,__GET_VAR(data__->TP3.Q,));
  __SET_VAR(data__->,LE16_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->JOYSICK,),
    (INT)__GET_VAR(data__->VALRET,)));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





