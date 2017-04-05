/*
 * 
 */


// Chip Select signal input
// pin 5 on arduino
// portD pin 5 on ATMEGA328
// green cable
#define HT1632_CS_PIN 5
#define HT1632_CS_HIGH PORTD |= (1<<5)
#define HT1632_CS_LOW PORTD &=~ (1<<5)

// Chip Select clock signal input
// pin 4 on arduino
// portD pin4 on ATMEGA328
// orange cable
#define HT1632_CLK_PIN 4
#define HT1632_CLK_HIGH PORTD |= (1<<4)
#define HT1632_CLK_LOW PORTD &=~ (1<<4)

// Write data clock input
// pin 6 on arduino
// portD pin6 on ATMEGA328
// yellow cable
#define HT1632_WR_PIN 6
#define HT1632_WR_HIGH PORTD |= (1<<6)
#define HT1632_WR_LOW PORTD &=~ (1<<6)

// Data input
// pin 7 on arduino
// portD pin7 on ATMEGA328
// blue cable
#define HT1632_DATA_PIN 7
#define HT1632_DATA_HIGH PORTD |= (1<<7)
#define HT1632_DATA_LOW PORTD &=~ (1<<7)

/*
 * commands written to the chip consist of a 3 bit "ID", followed by
 * either 9 bits of "Command code" or 7 bits of address + 4 bits of data.
 */
#define HT1632_ID_CMD        4  /* ID = 100 - Commands */
#define HT1632_ID_RD         6  /* ID = 110 - Read RAM */
#define HT1632_ID_WR         5  /* ID = 101 - Write RAM */

#define HT1632_CMD_SYSDIS 0x00  /* CMD= 0000-0000-x Turn off oscil */
#define HT1632_CMD_SYSON  0x01  /* CMD= 0000-0001-x Enable system oscil */
#define HT1632_CMD_LEDOFF 0x02  /* CMD= 0000-0010-x LED duty cycle gen off */
#define HT1632_CMD_LEDON  0x03  /* CMD= 0000-0011-x LEDs ON */
#define HT1632_CMD_BLOFF  0x08  /* CMD= 0000-1000-x Blink ON */
#define HT1632_CMD_BLON   0x09  /* CMD= 0000-1001-x Blink Off */
#define HT1632_CMD_SLVMD  0x10  /* CMD= 0001-00xx-x Slave Mode */
#define HT1632_CMD_MSTMD  0x14  /* CMD= 0001-01xx-x Master Mode */
#define HT1632_CMD_RCCLK  0x18  /* CMD= 0001-10xx-x Use on-chip clock */
#define HT1632_CMD_EXTCLK 0x1C  /* CMD= 0001-11xx-x Use external clock */
#define HT1632_CMD_COMS00 0x20  /* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS01 0x24  /* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS10 0x28  /* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS11 0x2C  /* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_PWM    0xA0  /* CMD= 101x-PPPP-x PWM duty cycle */

#define HT1632_ID_LEN     (1 << 2)  /* IDs are 3 bits */
#define HT1632_CMD_LEN    (1 << 7)  /* CMDs are 8 bits */
#define HT1632_DATA_LEN   (1 << 7)  /* Data are 4*2 bits */
#define HT1632_ADDR_LEN   (1 << 6)  /* Address are 7 bits */

void ht1632_sendcmd(int command) {
  // on selectionne le ou les HT1632C
  HT1632_CS_LOW;
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the first HT1632C is selected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the second HT1632C is selected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the third HT1632C is selected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the fourth HT1632C is selected

  

  // on déselectionne le ou les HT1632C
  HT1632_CS_HIGH;
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the first HT1632C is unselected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the second HT1632C is unselected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the third HT1632C is unselected
  // pulse
  HT1632_CLK_HIGH;
  HT1632_CLK_LOW;
  // the fourth HT1632C is unselected


  
}

void ht1632_setup() {
  ht1632_sendcmd(HT1632_CMD_SYSDIS);
  ht1632_sendcmd(HT1632_CMD_COMS00);
  ht1632_sendcmd(HT1632_CMD_MSTMD);
  ht1632_sendcmd(HT1632_CMD_RCCLK);
  ht1632_sendcmd(HT1632_CMD_SYSON);
  ht1632_sendcmd(HT1632_CMD_LEDON);
  ht1632_sendcmd(HT1632_CMD_PWM);
  
}



void setup() {
  // initialize the digital pin of the matrix an outputs
  pinMode(HT1632_CS_PIN, OUTPUT);
  HT1632_CS_HIGH;
  pinMode(HT1632_CLK_PIN, OUTPUT);
  HT1632_CLK_LOW;
  pinMode(HT1632_WR_PIN, OUTPUT);
  HT1632_WR_HIGH;
  pinMode(HT1632_DATA_PIN, OUTPUT);
  HT1632_DATA_HIGH;

  // setup
  
}


void loop() {
  
}

