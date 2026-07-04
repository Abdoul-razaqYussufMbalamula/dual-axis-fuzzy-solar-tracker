#include <Fuzzy.h>
#include <Servo.h>

Fuzzy *fuzzy = new Fuzzy();
Fuzzy *fuzzy2 = new Fuzzy();

// FuzzyInput e1
FuzzySet *e1_NB = new FuzzySet(-5.0, -5.0, -5.0, -3.5);
FuzzySet *e1_NO = new FuzzySet(-5.0, -3.5, -3.5, -1.5);
FuzzySet *e1_NK = new FuzzySet(-3.5, -1.5, -1.5, 0.0);
FuzzySet *e1_YS = new FuzzySet(-1.5, 0.0, 0.0, 1.5);
FuzzySet *e1_PK = new FuzzySet(0.0, 1.5, 1.5, 3.5);
FuzzySet *e1_PO = new FuzzySet(1.5, 3.5, 3.5, 5.0);
FuzzySet *e1_PB = new FuzzySet(3.5, 5.0, 5.0, 5.0);

// FuzzyInput de1
FuzzySet *de1_NB = new FuzzySet(-5.0, -5.0, -5.0, -3.5);
FuzzySet *de1_NO = new FuzzySet(-5.0, -3.5, -3.5, -1.5);
FuzzySet *de1_NK = new FuzzySet(-3.5, -1.5, -1.5, 0.0);
FuzzySet *de1_YS = new FuzzySet(-1.5, 0.0, 0.0, 1.5);
FuzzySet *de1_PK = new FuzzySet(0.0, 1.5, 1.5, 3.5);
FuzzySet *de1_PO = new FuzzySet(1.5, 3.5, 3.5, 5.0);
FuzzySet *de1_PB = new FuzzySet(3.5, 5.0, 5.0, 5.0);

// FuzzyInput e2
FuzzySet *e2_NB = new FuzzySet(-5.0, -5.0, -5.0, -3.5);
FuzzySet *e2_NO = new FuzzySet(-5.0, -3.5, -3.5, -1.5);
FuzzySet *e2_NK = new FuzzySet(-3.5, -1.5, -1.5, 0.0);
FuzzySet *e2_YS = new FuzzySet(-1.5, 0.0, 0.0, 1.5);
FuzzySet *e2_PK = new FuzzySet(0.0, 1.5, 1.5, 3.5);
FuzzySet *e2_PO = new FuzzySet(1.5, 3.5, 3.5, 5.0);
FuzzySet *e2_PB = new FuzzySet(3.5, 5.0, 5.0, 5.0);

// FuzzyInput de2
FuzzySet *de2_NB = new FuzzySet(-5.0, -5.0, -5.0, -3.5);
FuzzySet *de2_NO = new FuzzySet(-5.0, -3.5, -3.5, -1.5);
FuzzySet *de2_NK = new FuzzySet(-3.5, -1.5, -1.5, 0.0);
FuzzySet *de2_YS = new FuzzySet(-1.5, 0.0, 0.0, 1.5);
FuzzySet *de2_PK = new FuzzySet(0.0, 1.5, 1.5, 3.5);
FuzzySet *de2_PO = new FuzzySet(1.5, 3.5, 3.5, 5.0);
FuzzySet *de2_PB = new FuzzySet(3.5, 5.0, 5.0, 5.0);

// FuzzyOUTPUT out1
FuzzySet *out1_NB = new FuzzySet(0, 0, 0, 40);
FuzzySet *out1_NO = new FuzzySet(0, 40, 40, 70);
FuzzySet *out1_NK = new FuzzySet(40, 70, 70, 90);
FuzzySet *out1_YS = new FuzzySet(70, 90, 90, 110);
FuzzySet *out1_PK = new FuzzySet(90, 110, 110, 140);
FuzzySet *out1_PO = new FuzzySet(110, 140, 140, 180);
FuzzySet *out1_PB = new FuzzySet(140, 180, 180, 180);

// FuzzyOUTPUT out2
FuzzySet *out2_NB = new FuzzySet(0, 0, 0, 40);
FuzzySet *out2_NO = new FuzzySet(0, 40, 40, 70);
FuzzySet *out2_NK = new FuzzySet(40, 70, 70, 90);
FuzzySet *out2_YS = new FuzzySet(70, 90, 90, 110);
FuzzySet *out2_PK = new FuzzySet(90, 110, 110, 140);
FuzzySet *out2_PO = new FuzzySet(110, 140, 140, 180);
FuzzySet *out2_PB = new FuzzySet(140, 180, 180, 180);

double Ve1;
double Vde1;
double Ve2;
double Vde2;

#define D_SERVO_PIN 2
#define Y_SERVO_PIN 3

Servo D_SERVO;
Servo Y_SERVO;

double VAL_D_SERVO;
double VAL_Y_SERVO;

#define LDR0 A0
#define LDR1 A1
#define LDR2 A2
#define LDR3 A3

void setup() {
  Serial.begin(9600);

  pinMode(LDR0, INPUT);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);

  D_SERVO.attach(D_SERVO_PIN);
  Y_SERVO.attach(Y_SERVO_PIN);

  FuzzyInput *e1 = new FuzzyInput(1);
  e1->addFuzzySet(e1_NB);
  e1->addFuzzySet(e1_NO);
  e1->addFuzzySet(e1_NK);
  e1->addFuzzySet(e1_YS);
  e1->addFuzzySet(e1_PK);
  e1->addFuzzySet(e1_PO);
  e1->addFuzzySet(e1_PB);
  fuzzy->addFuzzyInput(e1);

  FuzzyInput *de1 = new FuzzyInput(2);
  de1->addFuzzySet(de1_NB);
  de1->addFuzzySet(de1_NO);
  de1->addFuzzySet(de1_NK);
  de1->addFuzzySet(de1_YS);
  de1->addFuzzySet(de1_PK);
  de1->addFuzzySet(de1_PO);
  de1->addFuzzySet(de1_PB);
  fuzzy->addFuzzyInput(de1);

  FuzzyInput *e2 = new FuzzyInput(3);
  e2->addFuzzySet(e2_NB);
  e2->addFuzzySet(e2_NO);
  e2->addFuzzySet(e2_NK);
  e2->addFuzzySet(e2_YS);
  e2->addFuzzySet(e2_PK);
  e2->addFuzzySet(e2_PO);
  e2->addFuzzySet(e2_PB);
  fuzzy2->addFuzzyInput(e2);

  FuzzyInput *de2 = new FuzzyInput(4);
  de2->addFuzzySet(de2_NB);
  de2->addFuzzySet(de2_NO);
  de2->addFuzzySet(de2_NK);
  de2->addFuzzySet(de2_YS);
  de2->addFuzzySet(de2_PK);
  de2->addFuzzySet(de2_PO);
  de2->addFuzzySet(de2_PB);
  fuzzy2->addFuzzyInput(de2);

  FuzzyOutput *out1 = new FuzzyOutput(1);
  out1->addFuzzySet(out1_NB);
  out1->addFuzzySet(out1_NO);
  out1->addFuzzySet(out1_NK);
  out1->addFuzzySet(out1_YS);
  out1->addFuzzySet(out1_PK);
  out1->addFuzzySet(out1_PO);
  out1->addFuzzySet(out1_PB);
  fuzzy->addFuzzyOutput(out1);

  FuzzyOutput *out2 = new FuzzyOutput(2);
  out2->addFuzzySet(out2_NB);
  out2->addFuzzySet(out2_NO);
  out2->addFuzzySet(out2_NK);
  out2->addFuzzySet(out2_YS);
  out2->addFuzzySet(out2_PK);
  out2->addFuzzySet(out2_PO);
  out2->addFuzzySet(out2_PB);
  fuzzy2->addFuzzyOutput(out2);

  /* 
  //Building FuzzyRule exp
  FuzzyRuleAntecedent *INPUTNAME = new FuzzyRuleAntecedent();
  INPUTNAME->joinWithAND(Ex, Dx);
  FuzzyRuleConsequent *OUTNAME = new FuzzyRuleConsequent();
  OUTNAME->addOutput(OUT_SETx);
  FuzzyRule *fuzzyRuleX = new FuzzyRule(X, INPUTNAME, OUTNAME);
  fuzzy->addFuzzyRule(fuzzyRuleX);
  */

  // Building FuzzyRule 1
  FuzzyRuleAntecedent *e1NBde1NB = new FuzzyRuleAntecedent();
  e1NBde1NB->joinWithAND(e1_NB, de1_NB);
  FuzzyRuleConsequent *out1NB = new FuzzyRuleConsequent();
  out1NB->addOutput(out1_NB);
  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, e1NBde1NB, out1NB);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Building FuzzyRule 2
  FuzzyRuleAntecedent *e1NBde1NO = new FuzzyRuleAntecedent();
  e1NBde1NO->joinWithAND(e1_NB, de1_NO);
  FuzzyRuleConsequent *out1NB2 = new FuzzyRuleConsequent();
  out1NB2->addOutput(out1_NB);
  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, e1NBde1NO, out1NB2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Building FuzzyRule 3
  FuzzyRuleAntecedent *e1NBde1NK = new FuzzyRuleAntecedent();
  e1NBde1NK->joinWithAND(e1_NB, de1_NK);
  FuzzyRuleConsequent *out1NB3 = new FuzzyRuleConsequent();
  out1NB3->addOutput(out1_NB);
  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, e1NBde1NK, out1NB3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  // Building FuzzyRule 4
  FuzzyRuleAntecedent *e1NBde1YS = new FuzzyRuleAntecedent();
  e1NBde1YS->joinWithAND(e1_NB, de1_YS);
  FuzzyRuleConsequent *out1NB4 = new FuzzyRuleConsequent();
  out1NB4->addOutput(out1_NB);
  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, e1NBde1YS, out1NB4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  // Building FuzzyRule 5
  FuzzyRuleAntecedent *e1NBde1PK = new FuzzyRuleAntecedent();
  e1NBde1PK->joinWithAND(e1_NB, de1_PK);
  FuzzyRuleConsequent *out1NO = new FuzzyRuleConsequent();
  out1NO->addOutput(out1_NO);
  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, e1NBde1PK, out1NO);
  fuzzy->addFuzzyRule(fuzzyRule5);

  //Building FuzzyRule 6
  FuzzyRuleAntecedent *e1NBde1PO = new FuzzyRuleAntecedent();
  e1NBde1PO->joinWithAND(e1_NB, de1_PO);
  FuzzyRuleConsequent *out1NK = new FuzzyRuleConsequent();
  out1NK->addOutput(out1_NK);
  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, e1NBde1PO, out1NK);
  fuzzy->addFuzzyRule(fuzzyRule6);

  //Building FuzzyRule 7
  FuzzyRuleAntecedent *e1NBde1PB = new FuzzyRuleAntecedent();
  e1NBde1PB->joinWithAND(e1_NB, de1_PB);
  FuzzyRuleConsequent *out1YS = new FuzzyRuleConsequent();
  out1YS->addOutput(out1_YS);
  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, e1NBde1PB, out1YS);
  fuzzy->addFuzzyRule(fuzzyRule7);

  //Building FuzzyRule 8
  FuzzyRuleAntecedent *e1NOde1NB = new FuzzyRuleAntecedent();
  e1NOde1NB->joinWithAND(e1_NO, de1_NB);
  FuzzyRuleConsequent *out1NB5 = new FuzzyRuleConsequent();
  out1NB5->addOutput(out1_NB);
  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, e1NOde1NB, out1NB5);
  fuzzy->addFuzzyRule(fuzzyRule8);

  //Building FuzzyRule 9
  FuzzyRuleAntecedent *e1NOde1NO = new FuzzyRuleAntecedent();
  e1NOde1NO->joinWithAND(e1_NO, de1_NO);
  FuzzyRuleConsequent *out1NB6 = new FuzzyRuleConsequent();
  out1NB6->addOutput(out1_NB);
  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, e1NOde1NO, out1NB6);
  fuzzy->addFuzzyRule(fuzzyRule9);

  //Building FuzzyRule 10
  FuzzyRuleAntecedent *e1NOde1NK = new FuzzyRuleAntecedent();
  e1NOde1NK->joinWithAND(e1_NO, de1_NK);
  FuzzyRuleConsequent *out1NO2 = new FuzzyRuleConsequent();
  out1NO2->addOutput(out1_NO);
  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, e1NOde1NK, out1NO2);
  fuzzy->addFuzzyRule(fuzzyRule10);

  //Building FuzzyRule 11
  FuzzyRuleAntecedent *e1NOde1YS = new FuzzyRuleAntecedent();
  e1NOde1YS->joinWithAND(e1_NO, de1_YS);
  FuzzyRuleConsequent *out1NO3 = new FuzzyRuleConsequent();
  out1NO3->addOutput(out1_NO);
  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, e1NOde1YS, out1NO3);
  fuzzy->addFuzzyRule(fuzzyRule11);

  //Building FuzzyRule 12
  FuzzyRuleAntecedent *e1NOde1PK = new FuzzyRuleAntecedent();
  e1NOde1PK->joinWithAND(e1_NO, de1_PK);
  FuzzyRuleConsequent *out1NK2 = new FuzzyRuleConsequent();
  out1NK2->addOutput(out1_NK);
  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, e1NOde1PK, out1NK2);
  fuzzy->addFuzzyRule(fuzzyRule12);

  //Building FuzzyRule 13
  FuzzyRuleAntecedent *e1NOde1PO = new FuzzyRuleAntecedent();
  e1NOde1PO->joinWithAND(e1_NO, de1_PO);
  FuzzyRuleConsequent *out1YS2 = new FuzzyRuleConsequent();
  out1YS2->addOutput(out1_YS);
  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, e1NOde1PO, out1YS2);
  fuzzy->addFuzzyRule(fuzzyRule13);

  //Building FuzzyRule 14
  FuzzyRuleAntecedent *e1NOde1PB = new FuzzyRuleAntecedent();
  e1NOde1PB->joinWithAND(e1_NO, de1_PB);
  FuzzyRuleConsequent *out1PK = new FuzzyRuleConsequent();
  out1PK->addOutput(out1_PK);
  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, e1NOde1PB, out1PK);
  fuzzy->addFuzzyRule(fuzzyRule14);

  //Building FuzzyRule 15
  FuzzyRuleAntecedent *e1NKde1NB = new FuzzyRuleAntecedent();
  e1NKde1NB->joinWithAND(e1_NK, de1_NB);
  FuzzyRuleConsequent *out1NB7 = new FuzzyRuleConsequent();
  out1NB7->addOutput(out1_NB);
  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, e1NKde1NB, out1NB7);
  fuzzy->addFuzzyRule(fuzzyRule15);

  //Building FuzzyRule 16
  FuzzyRuleAntecedent *e1NKde1NO = new FuzzyRuleAntecedent();
  e1NKde1NO->joinWithAND(e1_NK, de1_NO);
  FuzzyRuleConsequent *out1NO4 = new FuzzyRuleConsequent();
  out1NO4->addOutput(out1_NO);
  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, e1NKde1NO, out1NO4);
  fuzzy->addFuzzyRule(fuzzyRule16);

  //Building FuzzyRule 17
  FuzzyRuleAntecedent *e1NKde1NK = new FuzzyRuleAntecedent();
  e1NKde1NK->joinWithAND(e1_NK, de1_NK);
  FuzzyRuleConsequent *out1NK3 = new FuzzyRuleConsequent();
  out1NK3->addOutput(out1_NK);
  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, e1NKde1NK, out1NK3);
  fuzzy->addFuzzyRule(fuzzyRule17);

  //Building FuzzyRule 18
  FuzzyRuleAntecedent *e1NKde1YS = new FuzzyRuleAntecedent();
  e1NKde1YS->joinWithAND(e1_NK, de1_YS);
  FuzzyRuleConsequent *out1NK4 = new FuzzyRuleConsequent();
  out1NK4->addOutput(out1_NK);
  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, e1NKde1YS, out1NK4);
  fuzzy->addFuzzyRule(fuzzyRule18);

  //Building FuzzyRule 19
  FuzzyRuleAntecedent *e1NKde1PK = new FuzzyRuleAntecedent();
  e1NKde1PK->joinWithAND(e1_NK, de1_PK);
  FuzzyRuleConsequent *out1YS3 = new FuzzyRuleConsequent();
  out1YS3->addOutput(out1_YS);
  FuzzyRule *fuzzyRule19 = new FuzzyRule(19, e1NKde1PK, out1YS3);
  fuzzy->addFuzzyRule(fuzzyRule19);

  //Building FuzzyRule 20
  FuzzyRuleAntecedent *e1NKde1PO = new FuzzyRuleAntecedent();
  e1NKde1PO->joinWithAND(e1_NK, de1_PO);
  FuzzyRuleConsequent *out1PK2 = new FuzzyRuleConsequent();
  out1PK2->addOutput(out1_PK);
  FuzzyRule *fuzzyRule20 = new FuzzyRule(20, e1NKde1PO, out1PK2);
  fuzzy->addFuzzyRule(fuzzyRule20);

  //Building FuzzyRule 21
  FuzzyRuleAntecedent *e1NKde1PB = new FuzzyRuleAntecedent();
  e1NKde1PB->joinWithAND(e1_NK, de1_PB);
  FuzzyRuleConsequent *out1PO = new FuzzyRuleConsequent();
  out1PO->addOutput(out1_PO);
  FuzzyRule *fuzzyRule21 = new FuzzyRule(21, e1NKde1PB, out1PO);
  fuzzy->addFuzzyRule(fuzzyRule21);

  //Building FuzzyRule 22
  FuzzyRuleAntecedent *e1YSde1NB = new FuzzyRuleAntecedent();
  e1YSde1NB->joinWithAND(e1_YS, de1_NB);
  FuzzyRuleConsequent *out1NB8 = new FuzzyRuleConsequent();
  out1NB8->addOutput(out1_NB);
  FuzzyRule *fuzzyRule22 = new FuzzyRule(22, e1YSde1NB, out1NB8);
  fuzzy->addFuzzyRule(fuzzyRule22);

  //Building FuzzyRule 23
  FuzzyRuleAntecedent *e1YSde1NO = new FuzzyRuleAntecedent();
  e1YSde1NO->joinWithAND(e1_YS, de1_NO);
  FuzzyRuleConsequent *out1NO5 = new FuzzyRuleConsequent();
  out1NO5->addOutput(out1_NO);
  FuzzyRule *fuzzyRule23 = new FuzzyRule(23, e1YSde1NO, out1NO5);
  fuzzy->addFuzzyRule(fuzzyRule23);

  //Building FuzzyRule 24
  FuzzyRuleAntecedent *e1YSde1NK = new FuzzyRuleAntecedent();
  e1YSde1NK->joinWithAND(e1_YS, de1_NK);
  FuzzyRuleConsequent *out1NK5 = new FuzzyRuleConsequent();
  out1NK5->addOutput(out1_NK);
  FuzzyRule *fuzzyRule24 = new FuzzyRule(24, e1YSde1NK, out1NK5);
  fuzzy->addFuzzyRule(fuzzyRule24);

  //Building FuzzyRule 25
  FuzzyRuleAntecedent *e1YSde1YS = new FuzzyRuleAntecedent();
  e1YSde1YS->joinWithAND(e1_YS, de1_YS);
  FuzzyRuleConsequent *out1YS4 = new FuzzyRuleConsequent();
  out1YS4->addOutput(out1_YS);
  FuzzyRule *fuzzyRule25 = new FuzzyRule(25, e1YSde1YS, out1YS4);
  fuzzy->addFuzzyRule(fuzzyRule25);

  //Building FuzzyRule 26
  FuzzyRuleAntecedent *e1YSde1PK = new FuzzyRuleAntecedent();
  e1YSde1PK->joinWithAND(e1_YS, de1_PK);
  FuzzyRuleConsequent *out1PK3 = new FuzzyRuleConsequent();
  out1PK3->addOutput(out1_PK);
  FuzzyRule *fuzzyRule26 = new FuzzyRule(26, e1YSde1PK, out1PK3);
  fuzzy->addFuzzyRule(fuzzyRule26);

  //Building FuzzyRule 27
  FuzzyRuleAntecedent *e1YSde1PO = new FuzzyRuleAntecedent();
  e1YSde1PO->joinWithAND(e1_YS, de1_PO);
  FuzzyRuleConsequent *out1PO2 = new FuzzyRuleConsequent();
  out1PO2->addOutput(out1_PO);
  FuzzyRule *fuzzyRule27 = new FuzzyRule(27, e1YSde1PO, out1PO2);
  fuzzy->addFuzzyRule(fuzzyRule27);

  //Building FuzzyRule 28
  FuzzyRuleAntecedent *e1YSde1PB = new FuzzyRuleAntecedent();
  e1YSde1PB->joinWithAND(e1_YS, de1_PB);
  FuzzyRuleConsequent *out1PB = new FuzzyRuleConsequent();
  out1PB->addOutput(out1_PB);
  FuzzyRule *fuzzyRule28 = new FuzzyRule(28, e1YSde1PB, out1PB);
  fuzzy->addFuzzyRule(fuzzyRule28);

  //Building FuzzyRule 29
  FuzzyRuleAntecedent *e1PKde1NB = new FuzzyRuleAntecedent();
  e1PKde1NB->joinWithAND(e1_PK, de1_NB);
  FuzzyRuleConsequent *out1NO6 = new FuzzyRuleConsequent();
  out1NO6->addOutput(out1_NO);
  FuzzyRule *fuzzyRule29 = new FuzzyRule(29, e1PKde1NB, out1NO6);
  fuzzy->addFuzzyRule(fuzzyRule29);

  //Building FuzzyRule 30
  FuzzyRuleAntecedent *e1PKde1NO = new FuzzyRuleAntecedent();
  e1PKde1NO->joinWithAND(e1_PK, de1_NO);
  FuzzyRuleConsequent *out1NK6 = new FuzzyRuleConsequent();
  out1NK6->addOutput(out1_NK);
  FuzzyRule *fuzzyRule30 = new FuzzyRule(30, e1PKde1NO, out1NK6);
  fuzzy->addFuzzyRule(fuzzyRule30);

  //Building FuzzyRule 31
  FuzzyRuleAntecedent *e1PKde1NK = new FuzzyRuleAntecedent();
  e1PKde1NK->joinWithAND(e1_PK, de1_NK);
  FuzzyRuleConsequent *out1YS5 = new FuzzyRuleConsequent();
  out1YS5->addOutput(out1_YS);
  FuzzyRule *fuzzyRule31 = new FuzzyRule(31, e1PKde1NK, out1YS5);
  fuzzy->addFuzzyRule(fuzzyRule31);

  //Building FuzzyRule 32
  FuzzyRuleAntecedent *e1PKde1YS = new FuzzyRuleAntecedent();
  e1PKde1YS->joinWithAND(e1_PK, de1_YS);
  FuzzyRuleConsequent *out1PK4 = new FuzzyRuleConsequent();
  out1PK4->addOutput(out1_PK);
  FuzzyRule *fuzzyRule32 = new FuzzyRule(32, e1PKde1YS, out1PK4);
  fuzzy->addFuzzyRule(fuzzyRule32);

  //Building FuzzyRule 33
  FuzzyRuleAntecedent *e1PKde1PK = new FuzzyRuleAntecedent();
  e1PKde1PK->joinWithAND(e1_PK, de1_PK);
  FuzzyRuleConsequent *out1PK5 = new FuzzyRuleConsequent();
  out1PK5->addOutput(out1_PK);
  FuzzyRule *fuzzyRule33 = new FuzzyRule(33, e1PKde1PK, out1PK5);
  fuzzy->addFuzzyRule(fuzzyRule33);

  //Building FuzzyRule 34
  FuzzyRuleAntecedent *e1PKde1PO = new FuzzyRuleAntecedent();
  e1PKde1PO->joinWithAND(e1_PK, de1_PO);
  FuzzyRuleConsequent *out1PO3 = new FuzzyRuleConsequent();
  out1PO3->addOutput(out1_PO);
  FuzzyRule *fuzzyRule34 = new FuzzyRule(34, e1PKde1PO, out1PO3);
  fuzzy->addFuzzyRule(fuzzyRule34);

  //Building FuzzyRule 35
  FuzzyRuleAntecedent *e1PKde1PB = new FuzzyRuleAntecedent();
  e1PKde1PB->joinWithAND(e1_PK, de1_PB);
  FuzzyRuleConsequent *out1PB2 = new FuzzyRuleConsequent();
  out1PB2->addOutput(out1_PB);
  FuzzyRule *fuzzyRule35 = new FuzzyRule(35, e1PKde1PB, out1PB2);
  fuzzy->addFuzzyRule(fuzzyRule35);

  //Building FuzzyRule 36
  FuzzyRuleAntecedent *e1POde1NB = new FuzzyRuleAntecedent();
  e1POde1NB->joinWithAND(e1_PO, de1_NB);
  FuzzyRuleConsequent *out1NK7 = new FuzzyRuleConsequent();
  out1NK7->addOutput(out1_NK);
  FuzzyRule *fuzzyRule36 = new FuzzyRule(36, e1POde1NB, out1NK7);
  fuzzy->addFuzzyRule(fuzzyRule36);

  //Building FuzzyRule 37
  FuzzyRuleAntecedent *e1POde1NO = new FuzzyRuleAntecedent();
  e1POde1NO->joinWithAND(e1_PO, de1_NO);
  FuzzyRuleConsequent *out1YS6 = new FuzzyRuleConsequent();
  out1YS6->addOutput(out1_YS);
  FuzzyRule *fuzzyRule37 = new FuzzyRule(37, e1POde1NO, out1YS6);
  fuzzy->addFuzzyRule(fuzzyRule37);

  //Building FuzzyRule 38
  FuzzyRuleAntecedent *e1POde1NK = new FuzzyRuleAntecedent();
  e1POde1NK->joinWithAND(e1_PO, de1_NK);
  FuzzyRuleConsequent *out1PK6 = new FuzzyRuleConsequent();
  out1PK6->addOutput(out1_PK);
  FuzzyRule *fuzzyRule38 = new FuzzyRule(38, e1POde1NK, out1PK6);
  fuzzy->addFuzzyRule(fuzzyRule38);

  //Building FuzzyRule 39
  FuzzyRuleAntecedent *e1POde1YS = new FuzzyRuleAntecedent();
  e1POde1YS->joinWithAND(e1_PO, de1_YS);
  FuzzyRuleConsequent *out1PO4 = new FuzzyRuleConsequent();
  out1PO4->addOutput(out1_PO);
  FuzzyRule *fuzzyRule39 = new FuzzyRule(39, e1POde1YS, out1PO4);
  fuzzy->addFuzzyRule(fuzzyRule39);

  //Building FuzzyRule 40
  FuzzyRuleAntecedent *e1POde1PK = new FuzzyRuleAntecedent();
  e1POde1PK->joinWithAND(e1_PO, de1_PK);
  FuzzyRuleConsequent *out1PO5 = new FuzzyRuleConsequent();
  out1PO5->addOutput(out1_PO);
  FuzzyRule *fuzzyRule40 = new FuzzyRule(40, e1POde1PK, out1PO5);
  fuzzy->addFuzzyRule(fuzzyRule40);

  //Building FuzzyRule 41
  FuzzyRuleAntecedent *e1POde1PO = new FuzzyRuleAntecedent();
  e1POde1PO->joinWithAND(e1_PO, de1_PO);
  FuzzyRuleConsequent *out1PB3 = new FuzzyRuleConsequent();
  out1PB3->addOutput(out1_PB);
  FuzzyRule *fuzzyRule41 = new FuzzyRule(41, e1POde1PO, out1PB3);
  fuzzy->addFuzzyRule(fuzzyRule41);

  //Building FuzzyRule 42
  FuzzyRuleAntecedent *e1POde1PB = new FuzzyRuleAntecedent();
  e1POde1PB->joinWithAND(e1_PO, de1_PB);
  FuzzyRuleConsequent *out1PB4 = new FuzzyRuleConsequent();
  out1PB4->addOutput(out1_PB);
  FuzzyRule *fuzzyRule42 = new FuzzyRule(42, e1POde1PB, out1PB4);
  fuzzy->addFuzzyRule(fuzzyRule42);

  //Building FuzzyRule 43
  FuzzyRuleAntecedent *e1PBde1NB = new FuzzyRuleAntecedent();
  e1PBde1NB->joinWithAND(e1_PB, de1_NB);
  FuzzyRuleConsequent *out1YS7 = new FuzzyRuleConsequent();
  out1YS7->addOutput(out1_YS);
  FuzzyRule *fuzzyRule43 = new FuzzyRule(43, e1PBde1NB, out1YS7);
  fuzzy->addFuzzyRule(fuzzyRule43);

  //Building FuzzyRule 44
  FuzzyRuleAntecedent *e1PBde1NO = new FuzzyRuleAntecedent();
  e1PBde1NO->joinWithAND(e1_PB, de1_NO);
  FuzzyRuleConsequent *out1PK7 = new FuzzyRuleConsequent();
  out1PK7->addOutput(out1_PK);
  FuzzyRule *fuzzyRule44 = new FuzzyRule(44, e1PBde1NO, out1PK7);
  fuzzy->addFuzzyRule(fuzzyRule44);

  //Building FuzzyRule 45
  FuzzyRuleAntecedent *e1PBde1NK = new FuzzyRuleAntecedent();
  e1PBde1NK->joinWithAND(e1_PB, de1_NK);
  FuzzyRuleConsequent *out1PO6 = new FuzzyRuleConsequent();
  out1PO6->addOutput(out1_PO);
  FuzzyRule *fuzzyRule45 = new FuzzyRule(45, e1PBde1NK, out1PO6);
  fuzzy->addFuzzyRule(fuzzyRule45);

  //Building FuzzyRule 46
  FuzzyRuleAntecedent *e1PBde1YS = new FuzzyRuleAntecedent();
  e1PBde1YS->joinWithAND(e1_PB, de1_YS);
  FuzzyRuleConsequent *out1PB5 = new FuzzyRuleConsequent();
  out1PB5->addOutput(out1_PB);
  FuzzyRule *fuzzyRule46 = new FuzzyRule(46, e1PBde1YS, out1PB5);
  fuzzy->addFuzzyRule(fuzzyRule46);

  //Building FuzzyRule 47
  FuzzyRuleAntecedent *e1PBde1PK = new FuzzyRuleAntecedent();
  e1PBde1PK->joinWithAND(e1_PB, de1_PK);
  FuzzyRuleConsequent *out1PB6 = new FuzzyRuleConsequent();
  out1PB6->addOutput(out1_PB);
  FuzzyRule *fuzzyRule47 = new FuzzyRule(47, e1PBde1PK, out1PB6);
  fuzzy->addFuzzyRule(fuzzyRule47);

  //Building FuzzyRule 48
  FuzzyRuleAntecedent *e1PBde1PO = new FuzzyRuleAntecedent();
  e1PBde1PO->joinWithAND(e1_PB, de1_PO);
  FuzzyRuleConsequent *out1PB7 = new FuzzyRuleConsequent();
  out1PB7->addOutput(out1_PB);
  FuzzyRule *fuzzyRule48 = new FuzzyRule(48, e1PBde1PO, out1PB7);
  fuzzy->addFuzzyRule(fuzzyRule48);

  //Building FuzzyRule 49
  FuzzyRuleAntecedent *e1PBde1PB = new FuzzyRuleAntecedent();
  e1PBde1PB->joinWithAND(e1_PB, de1_PB);
  FuzzyRuleConsequent *out1PB8 = new FuzzyRuleConsequent();
  out1PB8->addOutput(out1_PB);
  FuzzyRule *fuzzyRule49 = new FuzzyRule(49, e1PBde1PB, out1PB8);
  fuzzy->addFuzzyRule(fuzzyRule49);

  /////////////////////////////_______e2 & de2________///////////////////////////////

  // Building FuzzyRule 50
  FuzzyRuleAntecedent *e2NBde2NB = new FuzzyRuleAntecedent();
  e2NBde2NB->joinWithAND(e2_NB, de2_NB);
  FuzzyRuleConsequent *out2NB = new FuzzyRuleConsequent();
  out2NB->addOutput(out2_NB);
  FuzzyRule *fuzzyRule50 = new FuzzyRule(50, e2NBde2NB, out2NB);
  fuzzy2->addFuzzyRule(fuzzyRule50);

  // Building FuzzyRule 51
  FuzzyRuleAntecedent *e2NBde2NO = new FuzzyRuleAntecedent();
  e2NBde2NO->joinWithAND(e2_NB, de2_NO);
  FuzzyRuleConsequent *out2NB2 = new FuzzyRuleConsequent();
  out2NB2->addOutput(out2_NB);
  FuzzyRule *fuzzyRule51 = new FuzzyRule(51, e2NBde2NO, out2NB2);
  fuzzy2->addFuzzyRule(fuzzyRule51);

  // Building FuzzyRule 52
  FuzzyRuleAntecedent *e2NBde2NK = new FuzzyRuleAntecedent();
  e2NBde2NK->joinWithAND(e2_NB, de2_NK);
  FuzzyRuleConsequent *out2NB3 = new FuzzyRuleConsequent();
  out2NB3->addOutput(out2_NB);
  FuzzyRule *fuzzyRule52 = new FuzzyRule(52, e2NBde2NK, out2NB3);
  fuzzy2->addFuzzyRule(fuzzyRule52);

  // Building FuzzyRule 53
  FuzzyRuleAntecedent *e2NBde2YS = new FuzzyRuleAntecedent();
  e2NBde2YS->joinWithAND(e2_NB, de2_YS);
  FuzzyRuleConsequent *out2NB4 = new FuzzyRuleConsequent();
  out2NB4->addOutput(out2_NB);
  FuzzyRule *fuzzyRule53 = new FuzzyRule(53, e2NBde2YS, out2NB4);
  fuzzy2->addFuzzyRule(fuzzyRule53);

  // Building FuzzyRule 54
  FuzzyRuleAntecedent *e2NBde2PK = new FuzzyRuleAntecedent();
  e2NBde2PK->joinWithAND(e2_NB, de2_PK);
  FuzzyRuleConsequent *out2NO = new FuzzyRuleConsequent();
  out2NO->addOutput(out2_NO);
  FuzzyRule *fuzzyRule54 = new FuzzyRule(54, e2NBde2PK, out2NO);
  fuzzy2->addFuzzyRule(fuzzyRule54);

  //Building FuzzyRule 55
  FuzzyRuleAntecedent *e2NBde2PO = new FuzzyRuleAntecedent();
  e2NBde2PO->joinWithAND(e2_NB, de2_PO);
  FuzzyRuleConsequent *out2NK = new FuzzyRuleConsequent();
  out2NK->addOutput(out2_NK);
  FuzzyRule *fuzzyRule55 = new FuzzyRule(55, e2NBde2PO, out2NK);
  fuzzy2->addFuzzyRule(fuzzyRule55);

  //Building FuzzyRule 56
  FuzzyRuleAntecedent *e2NBde2PB = new FuzzyRuleAntecedent();
  e2NBde2PB->joinWithAND(e2_NB, de2_PB);
  FuzzyRuleConsequent *out2YS = new FuzzyRuleConsequent();
  out2YS->addOutput(out2_YS);
  FuzzyRule *fuzzyRule56 = new FuzzyRule(56, e2NBde2PB, out2YS);
  fuzzy2->addFuzzyRule(fuzzyRule56);

  //Building FuzzyRule 57
  FuzzyRuleAntecedent *e2NOde2NB = new FuzzyRuleAntecedent();
  e2NOde2NB->joinWithAND(e2_NO, de2_NB);
  FuzzyRuleConsequent *out2NB5 = new FuzzyRuleConsequent();
  out2NB5->addOutput(out2_NB);
  FuzzyRule *fuzzyRule57 = new FuzzyRule(57, e2NOde2NB, out2NB5);
  fuzzy2->addFuzzyRule(fuzzyRule57);

  //Building FuzzyRule 58
  FuzzyRuleAntecedent *e2NOde2NO = new FuzzyRuleAntecedent();
  e2NOde2NO->joinWithAND(e2_NO, de2_NO);
  FuzzyRuleConsequent *out2NB6 = new FuzzyRuleConsequent();
  out2NB6->addOutput(out2_NB);
  FuzzyRule *fuzzyRule58 = new FuzzyRule(58, e2NOde2NO, out2NB6);
  fuzzy2->addFuzzyRule(fuzzyRule58);

  //Building FuzzyRule 59
  FuzzyRuleAntecedent *e2NOde2NK = new FuzzyRuleAntecedent();
  e2NOde2NK->joinWithAND(e2_NO, de2_NK);
  FuzzyRuleConsequent *out2NO2 = new FuzzyRuleConsequent();
  out2NO2->addOutput(out2_NO);
  FuzzyRule *fuzzyRule59 = new FuzzyRule(59, e2NOde2NK, out2NO2);
  fuzzy2->addFuzzyRule(fuzzyRule59);

  //Building FuzzyRule 60
  FuzzyRuleAntecedent *e2NOde2YS = new FuzzyRuleAntecedent();
  e2NOde2YS->joinWithAND(e2_NO, de2_YS);
  FuzzyRuleConsequent *out2NO3 = new FuzzyRuleConsequent();
  out2NO3->addOutput(out2_NO);
  FuzzyRule *fuzzyRule60 = new FuzzyRule(60, e2NOde2YS, out2NO3);
  fuzzy2->addFuzzyRule(fuzzyRule60);

  //Building FuzzyRule 61
  FuzzyRuleAntecedent *e2NOde2PK = new FuzzyRuleAntecedent();
  e2NOde2PK->joinWithAND(e2_NO, de2_PK);
  FuzzyRuleConsequent *out2NK2 = new FuzzyRuleConsequent();
  out2NK2->addOutput(out2_NK);
  FuzzyRule *fuzzyRule61 = new FuzzyRule(61, e2NOde2PK, out2NK2);
  fuzzy2->addFuzzyRule(fuzzyRule61);

  //Building FuzzyRule 62
  FuzzyRuleAntecedent *e2NOde2PO = new FuzzyRuleAntecedent();
  e2NOde2PO->joinWithAND(e2_NO, de2_PO);
  FuzzyRuleConsequent *out2YS2 = new FuzzyRuleConsequent();
  out2YS2->addOutput(out2_YS);
  FuzzyRule *fuzzyRule62 = new FuzzyRule(62, e2NOde2PO, out2YS2);
  fuzzy2->addFuzzyRule(fuzzyRule62);

  //Building FuzzyRule 63
  FuzzyRuleAntecedent *e2NOde2PB = new FuzzyRuleAntecedent();
  e2NOde2PB->joinWithAND(e2_NO, de2_PB);
  FuzzyRuleConsequent *out2PK = new FuzzyRuleConsequent();
  out2PK->addOutput(out2_PK);
  FuzzyRule *fuzzyRule63 = new FuzzyRule(63, e2NOde2PB, out2PK);
  fuzzy2->addFuzzyRule(fuzzyRule63);

  //Building FuzzyRule 64
  FuzzyRuleAntecedent *e2NKde2NB = new FuzzyRuleAntecedent();
  e2NKde2NB->joinWithAND(e2_NK, de2_NB);
  FuzzyRuleConsequent *out2NB7 = new FuzzyRuleConsequent();
  out2NB7->addOutput(out2_NB);
  FuzzyRule *fuzzyRule64 = new FuzzyRule(64, e2NKde2NB, out2NB7);
  fuzzy2->addFuzzyRule(fuzzyRule64);

  //Building FuzzyRule 65
  FuzzyRuleAntecedent *e2NKde2NO = new FuzzyRuleAntecedent();
  e2NKde2NO->joinWithAND(e2_NK, de2_NO);
  FuzzyRuleConsequent *out2NO4 = new FuzzyRuleConsequent();
  out2NO4->addOutput(out2_NO);
  FuzzyRule *fuzzyRule65 = new FuzzyRule(65, e2NKde2NO, out2NO4);
  fuzzy2->addFuzzyRule(fuzzyRule65);

  //Building FuzzyRule 66
  FuzzyRuleAntecedent *e2NKde2NK = new FuzzyRuleAntecedent();
  e2NKde2NK->joinWithAND(e2_NK, de2_NK);
  FuzzyRuleConsequent *out2NK3 = new FuzzyRuleConsequent();
  out2NK3->addOutput(out2_NK);
  FuzzyRule *fuzzyRule66 = new FuzzyRule(66, e2NKde2NK, out2NK3);
  fuzzy2->addFuzzyRule(fuzzyRule66);

  //Building FuzzyRule 67
  FuzzyRuleAntecedent *e2NKde2YS = new FuzzyRuleAntecedent();
  e2NKde2YS->joinWithAND(e2_NK, de2_YS);
  FuzzyRuleConsequent *out2NK4 = new FuzzyRuleConsequent();
  out2NK4->addOutput(out2_NK);
  FuzzyRule *fuzzyRule67 = new FuzzyRule(67, e2NKde2YS, out2NK4);
  fuzzy2->addFuzzyRule(fuzzyRule67);

  //Building FuzzyRule 68
  FuzzyRuleAntecedent *e2NKde2PK = new FuzzyRuleAntecedent();
  e2NKde2PK->joinWithAND(e2_NK, de2_PK);
  FuzzyRuleConsequent *out2YS3 = new FuzzyRuleConsequent();
  out2YS3->addOutput(out2_YS);
  FuzzyRule *fuzzyRule68 = new FuzzyRule(68, e2NKde2PK, out2YS3);
  fuzzy2->addFuzzyRule(fuzzyRule68);

  //Building FuzzyRule 69
  FuzzyRuleAntecedent *e2NKde2PO = new FuzzyRuleAntecedent();
  e2NKde2PO->joinWithAND(e2_NK, de2_PO);
  FuzzyRuleConsequent *out2PK2 = new FuzzyRuleConsequent();
  out2PK2->addOutput(out2_PK);
  FuzzyRule *fuzzyRule69 = new FuzzyRule(69, e2NKde2PO, out2PK2);
  fuzzy2->addFuzzyRule(fuzzyRule69);

  //Building FuzzyRule 70
  FuzzyRuleAntecedent *e2NKde2PB = new FuzzyRuleAntecedent();
  e2NKde2PB->joinWithAND(e2_NK, de2_PB);
  FuzzyRuleConsequent *out2PO = new FuzzyRuleConsequent();
  out2PO->addOutput(out2_PO);
  FuzzyRule *fuzzyRule70 = new FuzzyRule(70, e2NKde2PB, out2PO);
  fuzzy2->addFuzzyRule(fuzzyRule70);

  //Building FuzzyRule 71
  FuzzyRuleAntecedent *e2YSde2NB = new FuzzyRuleAntecedent();
  e2YSde2NB->joinWithAND(e2_YS, de2_NB);
  FuzzyRuleConsequent *out2NB8 = new FuzzyRuleConsequent();
  out2NB8->addOutput(out2_NB);
  FuzzyRule *fuzzyRule71 = new FuzzyRule(71, e2YSde2NB, out2NB8);
  fuzzy2->addFuzzyRule(fuzzyRule71);

  //Building FuzzyRule 72
  FuzzyRuleAntecedent *e2YSde2NO = new FuzzyRuleAntecedent();
  e2YSde2NO->joinWithAND(e2_YS, de2_NO);
  FuzzyRuleConsequent *out2NO5 = new FuzzyRuleConsequent();
  out2NO5->addOutput(out2_NO);
  FuzzyRule *fuzzyRule72 = new FuzzyRule(72, e2YSde2NO, out2NO5);
  fuzzy2->addFuzzyRule(fuzzyRule72);

  //Building FuzzyRule 73
  FuzzyRuleAntecedent *e2YSde2NK = new FuzzyRuleAntecedent();
  e2YSde2NK->joinWithAND(e2_YS, de2_NK);
  FuzzyRuleConsequent *out2NK5 = new FuzzyRuleConsequent();
  out2NK5->addOutput(out2_NK);
  FuzzyRule *fuzzyRule73 = new FuzzyRule(73, e2YSde2NK, out2NK5);
  fuzzy2->addFuzzyRule(fuzzyRule73);

  //Building FuzzyRule 74
  FuzzyRuleAntecedent *e2YSde2YS = new FuzzyRuleAntecedent();
  e2YSde2YS->joinWithAND(e2_YS, de2_YS);
  FuzzyRuleConsequent *out2YS4 = new FuzzyRuleConsequent();
  out2YS4->addOutput(out2_YS);
  FuzzyRule *fuzzyRule74 = new FuzzyRule(74, e2YSde2YS, out2YS4);
  fuzzy2->addFuzzyRule(fuzzyRule74);

  //Building FuzzyRule 75
  FuzzyRuleAntecedent *e2YSde2PK = new FuzzyRuleAntecedent();
  e2YSde2PK->joinWithAND(e2_YS, de2_PK);
  FuzzyRuleConsequent *out2PK3 = new FuzzyRuleConsequent();
  out2PK3->addOutput(out2_PK);
  FuzzyRule *fuzzyRule75 = new FuzzyRule(75, e2YSde2PK, out2PK3);
  fuzzy2->addFuzzyRule(fuzzyRule75);

  //Building FuzzyRule 76
  FuzzyRuleAntecedent *e2YSde2PO = new FuzzyRuleAntecedent();
  e2YSde2PO->joinWithAND(e2_YS, de2_PO);
  FuzzyRuleConsequent *out2PO2 = new FuzzyRuleConsequent();
  out2PO2->addOutput(out2_PO);
  FuzzyRule *fuzzyRule76 = new FuzzyRule(76, e2YSde2PO, out2PO2);
  fuzzy2->addFuzzyRule(fuzzyRule76);

  //Building FuzzyRule 77
  FuzzyRuleAntecedent *e2YSde2PB = new FuzzyRuleAntecedent();
  e2YSde2PB->joinWithAND(e2_YS, de2_PB);
  FuzzyRuleConsequent *out2PB = new FuzzyRuleConsequent();
  out2PB->addOutput(out2_PB);
  FuzzyRule *fuzzyRule77 = new FuzzyRule(77, e2YSde2PB, out2PB);
  fuzzy2->addFuzzyRule(fuzzyRule77);

  //Building FuzzyRule 78
  FuzzyRuleAntecedent *e2PKde2NB = new FuzzyRuleAntecedent();
  e2PKde2NB->joinWithAND(e2_PK, de2_NB);
  FuzzyRuleConsequent *out2NO6 = new FuzzyRuleConsequent();
  out2NO6->addOutput(out2_NO);
  FuzzyRule *fuzzyRule78 = new FuzzyRule(78, e2PKde2NB, out2NO6);
  fuzzy2->addFuzzyRule(fuzzyRule78);

  //Building FuzzyRule 79
  FuzzyRuleAntecedent *e2PKde2NO = new FuzzyRuleAntecedent();
  e2PKde2NO->joinWithAND(e2_PK, de2_NO);
  FuzzyRuleConsequent *out2NK6 = new FuzzyRuleConsequent();
  out2NK6->addOutput(out2_NK);
  FuzzyRule *fuzzyRule79 = new FuzzyRule(79, e2PKde2NO, out2NK6);
  fuzzy2->addFuzzyRule(fuzzyRule79);

  //Building FuzzyRule 80
  FuzzyRuleAntecedent *e2PKde2NK = new FuzzyRuleAntecedent();
  e2PKde2NK->joinWithAND(e2_PK, de2_NK);
  FuzzyRuleConsequent *out2YS5 = new FuzzyRuleConsequent();
  out2YS5->addOutput(out2_YS);
  FuzzyRule *fuzzyRule80 = new FuzzyRule(80, e2PKde2NK, out2YS5);
  fuzzy2->addFuzzyRule(fuzzyRule80);

  //Building FuzzyRule 81
  FuzzyRuleAntecedent *e2PKde2YS = new FuzzyRuleAntecedent();
  e2PKde2YS->joinWithAND(e2_PK, de2_YS);
  FuzzyRuleConsequent *out2PK4 = new FuzzyRuleConsequent();
  out2PK4->addOutput(out2_PK);
  FuzzyRule *fuzzyRule81 = new FuzzyRule(81, e2PKde2YS, out2PK4);
  fuzzy2->addFuzzyRule(fuzzyRule81);

  //Building FuzzyRule 82
  FuzzyRuleAntecedent *e2PKde2PK = new FuzzyRuleAntecedent();
  e2PKde2PK->joinWithAND(e2_PK, de2_PK);
  FuzzyRuleConsequent *out2PK5 = new FuzzyRuleConsequent();
  out2PK5->addOutput(out2_PK);
  FuzzyRule *fuzzyRule82 = new FuzzyRule(82, e2PKde2PK, out2PK5);
  fuzzy2->addFuzzyRule(fuzzyRule82);

  //Building FuzzyRule 83
  FuzzyRuleAntecedent *e2PKde2PO = new FuzzyRuleAntecedent();
  e2PKde2PO->joinWithAND(e2_PK, de2_PO);
  FuzzyRuleConsequent *out2PO3 = new FuzzyRuleConsequent();
  out2PO3->addOutput(out2_PO);
  FuzzyRule *fuzzyRule83 = new FuzzyRule(83, e2PKde2PO, out2PO3);
  fuzzy2->addFuzzyRule(fuzzyRule83);

  //Building FuzzyRule 84
  FuzzyRuleAntecedent *e2PKde2PB = new FuzzyRuleAntecedent();
  e2PKde2PB->joinWithAND(e2_PK, de2_PB);
  FuzzyRuleConsequent *out2PB2 = new FuzzyRuleConsequent();
  out2PB2->addOutput(out2_PB);
  FuzzyRule *fuzzyRule84 = new FuzzyRule(84, e2PKde2PB, out2PB2);
  fuzzy2->addFuzzyRule(fuzzyRule84);

  //Building FuzzyRule 85
  FuzzyRuleAntecedent *e2POde2NB = new FuzzyRuleAntecedent();
  e2POde2NB->joinWithAND(e2_PO, de2_NB);
  FuzzyRuleConsequent *out2NK7 = new FuzzyRuleConsequent();
  out2NK7->addOutput(out2_NK);
  FuzzyRule *fuzzyRule85 = new FuzzyRule(85, e2POde2NB, out2NK7);
  fuzzy2->addFuzzyRule(fuzzyRule85);

  //Building FuzzyRule 86
  FuzzyRuleAntecedent *e2POde2NO = new FuzzyRuleAntecedent();
  e2POde2NO->joinWithAND(e2_PO, de2_NO);
  FuzzyRuleConsequent *out2YS6 = new FuzzyRuleConsequent();
  out2YS6->addOutput(out2_YS);
  FuzzyRule *fuzzyRule86 = new FuzzyRule(86, e2POde2NO, out2YS6);
  fuzzy2->addFuzzyRule(fuzzyRule86);

  //Building FuzzyRule 87
  FuzzyRuleAntecedent *e2POde2NK = new FuzzyRuleAntecedent();
  e2POde2NK->joinWithAND(e2_PO, de2_NK);
  FuzzyRuleConsequent *out2PK6 = new FuzzyRuleConsequent();
  out2PK6->addOutput(out2_PK);
  FuzzyRule *fuzzyRule87 = new FuzzyRule(87, e2POde2NK, out2PK6);
  fuzzy2->addFuzzyRule(fuzzyRule87);

  //Building FuzzyRule 88
  FuzzyRuleAntecedent *e2POde2YS = new FuzzyRuleAntecedent();
  e2POde2YS->joinWithAND(e2_PO, de2_YS);
  FuzzyRuleConsequent *out2PO4 = new FuzzyRuleConsequent();
  out2PO4->addOutput(out2_PO);
  FuzzyRule *fuzzyRule88 = new FuzzyRule(88, e2POde2YS, out2PO4);
  fuzzy2->addFuzzyRule(fuzzyRule88);

  //Building FuzzyRule 89
  FuzzyRuleAntecedent *e2POde2PK = new FuzzyRuleAntecedent();
  e2POde2PK->joinWithAND(e2_PO, de2_PK);
  FuzzyRuleConsequent *out2PO5 = new FuzzyRuleConsequent();
  out2PO5->addOutput(out2_PO);
  FuzzyRule *fuzzyRule89 = new FuzzyRule(89, e2POde2PK, out2PO5);
  fuzzy2->addFuzzyRule(fuzzyRule89);

  //Building FuzzyRule 90
  FuzzyRuleAntecedent *e2POde2PO = new FuzzyRuleAntecedent();
  e2POde2PO->joinWithAND(e2_PO, de2_PO);
  FuzzyRuleConsequent *out2PB3 = new FuzzyRuleConsequent();
  out2PB3->addOutput(out2_PB);
  FuzzyRule *fuzzyRule90 = new FuzzyRule(90, e2POde2PO, out2PB3);
  fuzzy2->addFuzzyRule(fuzzyRule90);

  //Building FuzzyRule 91
  FuzzyRuleAntecedent *e2POde2PB = new FuzzyRuleAntecedent();
  e2POde2PB->joinWithAND(e2_PO, de2_PB);
  FuzzyRuleConsequent *out2PB4 = new FuzzyRuleConsequent();
  out2PB4->addOutput(out2_PB);
  FuzzyRule *fuzzyRule91 = new FuzzyRule(91, e2POde2PB, out2PB4);
  fuzzy2->addFuzzyRule(fuzzyRule91);

  //Building FuzzyRule 92
  FuzzyRuleAntecedent *e2PBde2NB = new FuzzyRuleAntecedent();
  e2PBde2NB->joinWithAND(e2_PB, de2_NB);
  FuzzyRuleConsequent *out2YS7 = new FuzzyRuleConsequent();
  out2YS7->addOutput(out2_YS);
  FuzzyRule *fuzzyRule92 = new FuzzyRule(92, e2PBde2NB, out2YS7);
  fuzzy2->addFuzzyRule(fuzzyRule92);

  //Building FuzzyRule 93
  FuzzyRuleAntecedent *e2PBde2NO = new FuzzyRuleAntecedent();
  e2PBde2NO->joinWithAND(e2_PB, de2_NO);
  FuzzyRuleConsequent *out2PK7 = new FuzzyRuleConsequent();
  out2PK7->addOutput(out2_PK);
  FuzzyRule *fuzzyRule93 = new FuzzyRule(93, e2PBde2NO, out2PK7);
  fuzzy2->addFuzzyRule(fuzzyRule93);

  //Building FuzzyRule 94
  FuzzyRuleAntecedent *e2PBde2NK = new FuzzyRuleAntecedent();
  e2PBde2NK->joinWithAND(e2_PB, de2_NK);
  FuzzyRuleConsequent *out2PO6 = new FuzzyRuleConsequent();
  out2PO6->addOutput(out2_PO);
  FuzzyRule *fuzzyRule94 = new FuzzyRule(94, e2PBde2NK, out2PO6);
  fuzzy2->addFuzzyRule(fuzzyRule94);

  //Building FuzzyRule 95
  FuzzyRuleAntecedent *e2PBde2YS = new FuzzyRuleAntecedent();
  e2PBde2YS->joinWithAND(e2_PB, de2_YS);
  FuzzyRuleConsequent *out2PB5 = new FuzzyRuleConsequent();
  out2PB5->addOutput(out2_PB);
  FuzzyRule *fuzzyRule95 = new FuzzyRule(95, e2PBde2YS, out2PB5);
  fuzzy2->addFuzzyRule(fuzzyRule95);

  //Building FuzzyRule 96
  FuzzyRuleAntecedent *e2PBde2PK = new FuzzyRuleAntecedent();
  e2PBde2PK->joinWithAND(e2_PB, de2_PK);
  FuzzyRuleConsequent *out2PB6 = new FuzzyRuleConsequent();
  out2PB6->addOutput(out2_PB);
  FuzzyRule *fuzzyRule96 = new FuzzyRule(96, e2PBde2PK, out2PB6);
  fuzzy2->addFuzzyRule(fuzzyRule96);

  //Building FuzzyRule 97
  FuzzyRuleAntecedent *e2PBde2PO = new FuzzyRuleAntecedent();
  e2PBde2PO->joinWithAND(e2_PB, de2_PO);
  FuzzyRuleConsequent *out2PB7 = new FuzzyRuleConsequent();
  out2PB7->addOutput(out2_PB);
  FuzzyRule *fuzzyRule97 = new FuzzyRule(97, e2PBde2PO, out2PB7);
  fuzzy2->addFuzzyRule(fuzzyRule97);

  //Building FuzzyRule 98
  FuzzyRuleAntecedent *e2PBde2PB = new FuzzyRuleAntecedent();
  e2PBde2PB->joinWithAND(e2_PB, de2_PB);
  FuzzyRuleConsequent *out2PB8 = new FuzzyRuleConsequent();
  out2PB8->addOutput(out2_PB);
  FuzzyRule *fuzzyRule98 = new FuzzyRule(98, e2PBde2PB, out2PB8);
  fuzzy2->addFuzzyRule(fuzzyRule98);
}

double mapf(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
  /*
  double Vsol = ((double)(mapf(analogRead(LDR0), 0, 1023, 0, 5) + mapf(analogRead(LDR2), 0, 1023, 0, 5)) / 2);
  double Vsag = ((double)(mapf(analogRead(LDR1), 0, 1023, 0, 5) + mapf(analogRead(LDR3), 0, 1023, 0, 5)) / 2);
  double Vust = ((double)(mapf(analogRead(LDR0), 0, 1023, 0, 5) + mapf(analogRead(LDR1), 0, 1023, 0, 5)) / 2);
  double Valt = ((double)(mapf(analogRead(LDR2), 0, 1023, 0, 5) + mapf(analogRead(LDR3), 0, 1023, 0, 5)) / 2);
  */
  double Vsol = ((analogRead(LDR0) + analogRead(LDR2)) / 2);
  double Vsag = ((analogRead(LDR1) + analogRead(LDR3)) / 2);
  double Vust = ((analogRead(LDR0) + analogRead(LDR1)) / 2);
  double Valt = ((analogRead(LDR2) + analogRead(LDR3)) / 2);

  Ve1 = Vsol - Vsag;
  Ve2 = Vust - Valt;

  Ve1 = mapf(Ve1, -1023.0, 1023.0, -5.0, 5.0);
  Ve2 = mapf(Ve2, -1023.0, 1023.0, -5.0, 5.0);

  if (abs(Ve1 - Vde1) < 0.05 && abs(Ve2 - Vde2) < 0.05) {
    //Nothing
  } else {

    fuzzy->setInput(1, Ve1);
    fuzzy->setInput(2, Vde1);
    fuzzy2->setInput(3, Ve2);
    fuzzy2->setInput(4, Vde2);

    fuzzy->fuzzify();
    fuzzy2->fuzzify();

    double output1 = fuzzy->defuzzify(1);
    double output2 = fuzzy2->defuzzify(2);

    /*
   D_SERVO.write(output1);
   Y_SERVO.write(output2);
  */

    Vde1 = Ve1;
    //Vde1 = Ve1 - Vde1;
    Vde1 = constrain(Vde1, -5, 5);

    Vde2 = Ve2;
    //Vde2 = Ve2 - Vde2;
    Vde2 = constrain(Vde2, -5, 5);
    // /*
    //TEST
    Serial.print(" e1: ");
    Serial.print(Ve1);
    Serial.print(" e2: ");
    Serial.print(Ve2);

    Serial.print(" Vde1: ");
    Serial.print(Vde1);
    Serial.print(" Vde2: ");
    Serial.print(Vde2);

    Serial.print(" out1: ");
    Serial.print(output1);
    Serial.print(" out2: ");
    Serial.println(output2);
    // */
    output1 = map(output1, 0, 180, 180, 0);
    Y_SERVO.write(output1);
    D_SERVO.write(output2);
    delay(250);
  }
}