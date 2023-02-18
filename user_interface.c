int user_interface()
{
    int num;
    printf("\n                  ######### WELCOME #########\n");
    printf("Please select from the following option\n1.Donate books\n2.Borrow Available Books\n3.Close Application");
    printf("\nEnter your choice here: ");
    scanf("%d",&num);
    if (num == 1)
    {
        return 1;
    }
    else if (num == 2)
    {
        return 2;
    }
    else if (num == 3)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}