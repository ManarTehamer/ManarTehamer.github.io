/*
 * INT_Private.h
 *
 * Created: 2/15/2023 3:11:21 PM
 *  Author: HP2023
 */ 


#ifndef INT_PRIVATE_H_
#define INT_PRIVATE_H_

#define SREG   (*((volatile u8 *)0x5F))
#define I_BIT  7

#define GICR   (*((volatile u8 *)0x5B))
#define  INT1_EN   7
#define  INT0_EN   6
#define  INT2_EN   5

#define GIFR   (*((volatile u8 *)0x5A))
#define  INTF1    7
#define  INTF0	  6
#define  INTF2	  5

#define MCUCR   (*((volatile u8 *)0x55))
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3

#define MCUCSR   (*((volatile u8 *)0x54))
#define ISC2   6






#endif /* INT_PRIVATE_H_ */