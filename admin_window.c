int admin_window()
{
    int num;
    printf("\n                     ######## ADMIN WINDOW ########\n");
    printf("\nPlease select the task you want to perform: \n");
    printf("1.View available books\n2.Delete Books\n3.Close Application\n");
    printf("Enter your choice here: ");
    scanf("%d", &num);
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