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
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR
    Joysick : REAL := 0.25;
  END_VAR
  VAR
    ValAv : REAL := 3.0;
    ValRet : REAL := 0.3;
  END_VAR
  VAR
    BobinaA : BOOL := 0;
    BobinaB : BOOL := 0;
    BobinaC : BOOL := 0;
    BobinaD : BOOL := 0;
  END_VAR
  VAR
    Reloj : TIME := T#5s;
    RelojA : TIME := T#0s;
    RelojB : TIME := T#5s;
    RelojC : TIME := T#2.5s;
    RelojD : TIME := T#7.5s;
    Clock : TIME := T#15s;
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
    GT17_OUT : BOOL;
    AND45_OUT : BOOL;
    LE16_OUT : BOOL;
  END_VAR

  TON4(IN := NOT(BobinaA), PT := Clock);
  TP4(IN := TON4.Q, PT := Clock);
  BobinaA := TP4.Q;
  GT17_OUT := GT(Joysick, ValAv);
  AND45_OUT := AND(TP4.Q, GT17_OUT);
  TON0(IN := AND45_OUT, PT := RelojA);
  TP0(IN := TON0.Q, PT := Reloj);
  BobinaA := TP0.Q;
  TON1(IN := AND45_OUT, PT := RelojB);
  TP1(IN := TON1.Q, PT := Reloj);
  BobinaB := TP1.Q;
  TON2(IN := AND45_OUT, PT := RelojC);
  TP2(IN := TON2.Q, PT := Reloj);
  BobinaC := TP2.Q;
  TON3(IN := AND45_OUT, PT := RelojD);
  TP3(IN := TON3.Q, PT := Reloj);
  BobinaD := TP3.Q;
  LE16_OUT := LE(Joysick, ValRet);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
