PROGRAM program0
  VAR
    Avance : BOOL := 0;
    Retroceso : BOOL := 0;
    Joysick : REAL := 0.25;
    ValAv : REAL := 3.0;
    ValRet : REAL := 0.3;
    ValRep : REAL;
    Reposo : BOOL;
    GT17_OUT : BOOL;
    NOT21_OUT : BOOL;
    LE16_OUT : BOOL;
    NOT22_OUT : BOOL;
    AND20_OUT : BOOL;
  END_VAR

  GT17_OUT := GT(Joysick, ValAv);
  Avance := GT17_OUT;
  NOT21_OUT := NOT(GT17_OUT);
  LE16_OUT := LE(Joysick, ValRet);
  NOT22_OUT := NOT(LE16_OUT);
  AND20_OUT := AND(NOT21_OUT, NOT22_OUT);
  Reposo := AND20_OUT;
  Retroceso := LE16_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
