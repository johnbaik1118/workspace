int g_iIndex = 0;
void increment(void) 
{
	g_iIndex++;
}
void main(void)
{
	for(;;) { 
		increment();
	}
}
