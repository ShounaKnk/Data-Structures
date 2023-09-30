    temp -> prev = NULL;
        temp -> next = start;
        *start -> prev = temp;
        *start = temp;