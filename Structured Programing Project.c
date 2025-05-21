#include <stdio.h>

int main() {
    int arr[100];
    int s = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input array size and values\n");
        printf("2. Update array\n");
        printf("3. Delete an element\n");
        printf("4. Display array\n");
        printf("5. Sort array (Ascending/Descending)\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the size of the array (1-100): ");
                scanf("%d", &s);
                if (s <= 0 || s > 100) {
                    printf("Invalid size. Must be between 1 and 100.\n");
                    s = 0;
                    break;
                }
                printf("Enter %d values:\n", s);
                for (int i = 0; i < s; i++) {
                    printf("Value %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }

            case 2: {
                if (s == 0) {
                    printf("Array is not initialized. Use option 1 first.\n");
                    break;
                }
                int i;
                printf("Enter the index to update (0 to %d): ", s - 1);
                scanf("%d", &i);
                if (i >= 0 && i < s) {
                    printf("Enter the new value: ");
                    scanf("%d", &arr[i]);
                    printf("Index %d updated.\n", i);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }

            case 3: {
                if (s == 0) {
                    printf("Array is not initialized. Use option 1 first.\n");
                    break;
                }
                int v;
                printf("Enter value to delete: ");
                scanf("%d", &v);
                int found = 0;
                for (int i = 0; i < s; i++) {
                    if (arr[i] == v) {
                        for (int j = i; j < s - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        s--;
                        found = 1;
                        printf("Value %d deleted.\n", v);
                        break;
                    }
                }
                if (!found) {
                    printf("Value not found.\n");
                }
                break;
            }

            case 4: {
                if (s == 0) {
                    printf("Array is empty or not initialized.\n");
                    break;
                }
                printf("Array elements: ");
                for (int i = 0; i < s; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }

            case 5: {
                if (s == 0) {
                    printf("Array is not initialized. Use option 1 first.\n");
                    break;
                }
                char o;
                printf("Enter A for Ascending or D for Descending: ");
                scanf(" %c", &o);
                if (o != 'A' && o != 'a' && o != 'D' && o != 'd') {
                    printf("Invalid option. Use A or D.\n");
                    break;
                }
                for (int i = 0; i < s - 1; i++) {
                    for (int j = i + 1; j < s; j++) {
                        if ((o == 'A' || o == 'a') && arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        } else if ((o == 'D' || o == 'd') && arr[i] < arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Array sorted %s.\n", (o == 'A' || o == 'a') ? "ascending" : "descending");
                break;
            }

            case 6: {
                if (s == 0) {
                    printf("Array is not initialized. Use option 1 first.\n");
                    break;
                }
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                int indices[100], count = 0;
                for (int i = 0; i < s; i++) {
                    if (arr[i] == value) {
                        indices[count++] = i;
                    }
                }
                if (count == 0) {
                    printf("Value %d not found.\n", value);
                } else if (count == 1) {
                    printf("Value %d found at index %d.\n", value, indices[0]);
                } else {
                    printf("Value %d found at %d indices: ", value, count);
                    for (int i = 0; i < count; i++) {
                        printf("%d ", indices[i]);
                    }
                    printf("\nEnter the index number to select: ");
                    int selected;
                    scanf("%d", &selected);
                    int valid = 0;
                    for (int i = 0; i < count; i++) {
                        if (indices[i] == selected) {
                            printf("Selected value %d at index %d.\n", value, selected);
                            valid = 1;
                            break;
                        }
                    }
                    if (!valid) {
                        printf("Invalid index selected.\n");
                    }
                }
                break;
            }

            case 7: {
                printf("Program Terminated\n");
                return 0;
            }

            default: {
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
            }
        }
    }

    return 0;
}
