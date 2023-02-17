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
    else
    {
        return 2;
    }
}