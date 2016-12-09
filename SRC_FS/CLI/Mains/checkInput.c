/*
 *(c) Zachary Job
 *4/15/2015
 *All rights reserved, Viewable for educational purposes without modification
 */

char checkInput(char *input)
{
	if(input[0] == 1)
		return 1;
	char *temp = input;
	for(;(*temp > 0) && ((*temp == '(') || (*temp == ')') || (*temp == '~') || (*temp == '.') || ((*temp >= '0') && (*temp <= '9')) || ((*temp >= 'A') && (*temp <= 'Z')) || ((*temp >= 'a') && (*temp <= 'z')));temp++);
	if(*temp != 0)
		return 2;
	return 1;
}