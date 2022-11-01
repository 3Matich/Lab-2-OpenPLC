PROGRAM program0
  VAR
    Joysick AT %IW0 : INT := 512;
  END_VAR
  VAR
    ValAv : INT := 700;
    ValRet : INT := 300;
  END_VAR
  VAR
    BobinaA AT %QX0.3 : BOOL := 0;
    BobinaB AT %QX0.1 : BOOL := 0;
    BobinaC AT %QX0.0 : BOOL := 0;
    BobinaD AT %QX0.2 : BOOL := 0;
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
