TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    Joysick : INT := 512;
  END_VAR
  VAR
    ValAv : INT := 700;
    ValRet : INT := 300;
  END_VAR
  VAR
    BobinaA : BOOL := 0;
    BobinaB : BOOL := 0;
    BobinaC : BOOL := 0;
    BobinaD : BOOL := 0;
  END_VAR
  VAR
    Reloj : TIME := T#200ms;
    RelojA : TIME := T#0ms;
    RelojB : TIME := T#200ms;
    RelojC : TIME := T#400ms;
    RelojD : TIME := T#600ms;
    Clock : TIME := T#1s400ms;
    TON0 : TON;
    TON1 : TON;
    TP0 : TP;
    TP1 : TP;
    TON2 : TON;
    TP2 : TP;
    TON3 : TON;
    TP3 : TP;
    TON4 : TON;
    TP4 : TP;
    _TMP_GT17_OUT : BOOL;
    _TMP_AND45_OUT : BOOL;
    _TMP_LE16_OUT : BOOL;
  END_VAR

  TON4(IN := NOT(BobinaA), PT := Clock);
  TP4(IN := TON4.Q, PT := Clock);
  BobinaA := TP4.Q;
  _TMP_GT17_OUT := GT(Joysick, ValAv);
  _TMP_AND45_OUT := AND(TP4.Q, _TMP_GT17_OUT);
  TON0(IN := _TMP_AND45_OUT, PT := RelojA);
  TP0(IN := TON0.Q, PT := Reloj);
  BobinaA := TP0.Q;
  TON1(IN := _TMP_AND45_OUT, PT := RelojB);
  TP1(IN := TON1.Q, PT := Reloj);
  BobinaB := TP1.Q;
  TON2(IN := _TMP_AND45_OUT, PT := RelojC);
  TP2(IN := TON2.Q, PT := Reloj);
  BobinaC := TP2.Q;
  TON3(IN := _TMP_AND45_OUT, PT := RelojD);
  TP3(IN := TON3.Q, PT := Reloj);
  BobinaD := TP3.Q;
  _TMP_LE16_OUT := LE(Joysick, ValRet);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
