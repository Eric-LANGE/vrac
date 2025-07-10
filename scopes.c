int function_1(int variable_1, int variable_2)
{
    int variable_3;
    
    variable_3 = variable_1 + variable_2;
    return (variable_3);
}

/*
 * THE PROGRAM ALWAYS STARTS WITH MAIN FUNCTION
 */
int main(void)
{
    int a;
    int b;

    b = 5;
    a = function_1(b, 2);

    return (0);
}
