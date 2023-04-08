/*
 * BIT_MATHS.h
 *
 * Created: 2/15/2023 12:35:54 PM
 *  Author: HP2023
 */ 


#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_


#define SET_BIT(REG,BN)  ((REG)|=(1<<(BN)))
#define CLR_BIT(REG,BN)  ((REG)&=~(1<<(BN)))
#define TOG_BIT(REG,BN)  ((REG)^=(1<<(BN)))
#define GET_BIT(REG,BN)  ( (REG>>BN)&1   )  //((REG & 1<<BN) >>BN)
#define ROR(REG,N)       (((REG)>>(N))|((REG)<<(8-(N))))
#define ROL(REG,N)       (((REG)<<(N))|((REG)>>(8-(N))))
#define IS_HIGH(REG,N) 	 (((REG)>>(N))&1)
#define IS_LOW(REG,N)	 (!(((REG)>>(N))&1))




#endif /* BIT_MATHS_H_ */