int admin()
{
    int password;
    printf("\n                  ######### ADMIN LOGIN #########\n");
    printf("Password: ");
    scanf("%d", &password);
    if (password == 23)
    {
        return 1;
    }
    else if (password == 1)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}