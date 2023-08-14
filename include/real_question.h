/*------------------------------------------------------------------------------
 * @file    REAL_QUESTION.H
 * @author  t-rex 
 * @date    2023/08/14 08:41:43
 * @brief   机试真题收集.
 * -----------------------------------------------------------------------------
 * @attention 
 
 * THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE 
 * CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE 
 * TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH 
 * HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN 
 * CONNECTION WITH PRODUCTS MADE BY CUSTOMERS. 
 * 
 * <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2> 
------------------------------------------------------------------------------*/

/* Define to prevent recursive inclusion  ------------------------------------*/
#ifndef __REAL_QUESTION_H
#define __REAL_QUESTION_H

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/
#ifdef _REAL_QUESTION_C_
#define GLOBAL



#else
#define GLOBAL extern
#endif



#undef GLOBAL

/* Functions ----------------------------------------------------------------*/

class RealQuestion
{
public:
    RealQuestion(){}
    ~RealQuestion(){}

    void question1();
private:

};

#endif
