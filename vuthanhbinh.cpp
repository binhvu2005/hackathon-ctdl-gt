#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

typedef struct {
    Node* head;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
}

void addFirst(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void addLast(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAt(LinkedList* list, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* temp = list->head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Vi tri khong hop le!\n");
        }
    }
}

void removeFirst(LinkedList* list) {
    if (list->head != NULL) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        printf("Danh sach rong!\n");
    }
}

void removeLast(LinkedList* list) {
    if (list->head == NULL) {
        printf("Danh sach rong!\n");
    } else if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void removeByValue(LinkedList* list, int value) {
    if (list->head == NULL) {
        printf("Danh sach rong!\n");
    } else {
        if (list->head->data == value) {
            Node* temp = list->head;
            list->head = list->head->next;
            free(temp);
        } else {
            Node* temp = list->head;
            while (temp->next != NULL && temp->next->data != value) {
                temp = temp->next;
            }
            if (temp->next != NULL) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            } else {
                printf("Khong tim thay gia tri %d\n", value);
            }
        }
    }
}

int search(LinkedList* list, int value) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList(LinkedList* list) {
    if (list->head == NULL) {
        printf("Danh sach rong!\n");
    } else {
        Node* temp = list->head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    LinkedList list;
    initList(&list);
    
    int choice, value, position;

    while (1) {
        printf("==================MENU=================\n");
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Chen phan tu vao vi tri cu the\n");
        printf("4. Xoa phan tu dau danh sach\n");
        printf("5. Xoa phan tu cuoi danh sach\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Tim kiem phan tu theo gia tri\n");
        printf("8. In danh sach cac gia tri ra man hinh\n");
        printf("9. Thoat\n");
        printf("=======================================\n");
        printf("Chon thao tac (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                addFirst(&list, value);
                printf("\nthem %d vao dau danh sach thanh cong!!!",value);
                sleep(1);
                system("cls");
                break;
            case 2:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                addLast(&list, value);
                printf("\nthem %d vao cuoi danh sach thanh cong!!!",value);
                sleep(1);
                system("cls");
                break;
            case 3:
                printf("Nhap gia tri va vi tri: ");
                scanf("%d %d", &value, &position);
                insertAt(&list, value, position);
                printf("\n chen %d vao vi tri %d trong danh sach thanh cong!!!",value,position);
                sleep(2);
                system("cls");
                break;
            case 4:
                removeFirst(&list);
                printf("\n xoa phan tu dau tien trong danh sach thanh cong!!!");
                sleep(1);
                system("cls");
                break;
            case 5:
                removeLast(&list);
        		printf("\n xoa phan tu cuoi cung trong danh sach thanh cong!!!");
                sleep(1);
                system("cls");
                break;
            case 6:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                removeByValue(&list, value);
                printf("\n xoa %d trong danh sach thanh cong!!!",value);
                sleep(1);
                system("cls");
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (search(&list, value)) {
                    printf("Tim thay gia tri %d trong danh sach!\n", value);
                } else {
                    printf("Khong tim thay gia tri!\n");
                }
                sleep(3);
                system("cls");
                break;
            case 8:
                printList(&list);
                sleep(5);
                system("cls");
                break;
            case 9:
                printf("Thoat chuong trinh!\n");
                return 0;
            default:
                printf("Lua chon khong hop le vui long chon lai!\n");
                sleep(1);
                system("cls");
                break;
        }
    }
}

