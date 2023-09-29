
void SREG_vid_EnableBitI(void)
{
    asm("SEI");
}

void SREG_vid_ClearBitI(void)
{
    asm("CLI");

}