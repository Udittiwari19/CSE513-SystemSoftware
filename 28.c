/*
============================================================================
Name : 28.c
Author : Udit Tiwari
Description : Write a program to get maximum and minimum real time priority 
Date: 7th Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<sched.h>

int main(){
    int max_fifo,min_fifo;
    int max_rr,min_rr;

    max_fifo=sched_get_priority_max(SCHED_FIFO);
    min_fifo=sched_get_priority_min(SCHED_FIFO);

    max_rr=sched_get_priority_max(SCHED_RR);
    min_rr=sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO -> Max Priority: %d, Min Priority: %d\n",max_fifo,min_fifo);
    printf("RR_FIFO -> Max Priority: %d, Min Priority: %d\n",max_rr,min_rr);
}