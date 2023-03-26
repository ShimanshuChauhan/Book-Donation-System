int admin_window()
{
    int num;
    printf("\n                     ######## ADMIN WINDOW ########\n");
    printf("\nPlease select the task you want to perform: \n");
    printf("1.Search available books\n2.Delete Record\n3.Add User\n4.Update record\n5.Display Record\n6.Close Application\n");
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
    else if (num == 4)
    {
        return 4;
    }
    else if (num == 5)
    {
        return 5;
    }

    else if (num == 6)
    {
        return 6;
    }

    else
    {
        return -1;
    }
}
