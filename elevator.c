#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 4

// 乘客请求
typedef struct {
    int startFloor;
    int destinationFloor;
} PassengerRequest;

// 电梯状态
typedef enum {
    IDLE,
    UP,
    DOWN
} ElevatorState;

// 电梯运行参数
typedef struct {
    ElevatorState state;
    int currentFloor;
    int passengers;
} Elevator;

int main() {
    Elevator elevator;
    elevator.state = IDLE;
    elevator.currentFloor = 1;
    elevator.passengers = 0;

    PassengerRequest requests[MAX_FLOORS];
    int numRequests = 0;

    printf("请输入乘客请求（起始楼层和目的楼层），输入-1结束输入:\n");

    int startFloor, destinationFloor;
    while (1) {
        printf("乘客请求 %d: ", numRequests + 1);
        scanf("%d %d", &startFloor, &destinationFloor);

        if (startFloor == -1 || destinationFloor == -1) {
            break;
        }

        if (startFloor < 1 || startFloor > MAX_FLOORS || destinationFloor < 1 || destinationFloor > MAX_FLOORS) {
            printf("输入的楼层不合法，请重新输入。\n");
            continue;
        }

        requests[numRequests].startFloor = startFloor;
        requests[numRequests].destinationFloor = destinationFloor;
        numRequests++;
    }

    // 排序乘客请求
    int i, j;
    for (i = 0; i < numRequests - 1; i++) {
        for (j = 0; j < numRequests - i - 1; j++) {
            if (requests[j].startFloor > requests[j + 1].startFloor) {
                PassengerRequest temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // 电梯运行
    while (numRequests > 0) {
        // 电梯向上运行
        for (i = elevator.currentFloor; i <= MAX_FLOORS; i++) {
            // 检查是否有乘客在当前楼层上电梯
            for (j = 0; j < numRequests; j++) {
                if (requests[j].startFloor == i) {
                    if (elevator.passengers < MAX_CAPACITY) {
                        printf("电梯停留在第%d层，乘客准备从%d楼到达%d楼\n", elevator.currentFloor, requests[j].startFloor, requests[j].destinationFloor);
                        elevator.passengers++;
                        numRequests--;

                        // 将乘客请求从数组中删除
                        for (int k = j; k < numRequests; k++) {
                            requests[k] = requests[k + 1];
                        }
                    } else {
                        printf("电梯已满载，无法接纳更多乘客\n");
                    }
                }
            }
            
            // 检查是否有乘客在当前楼层按下电梯按钮
            for (j = 0; j < numRequests; j++) {
                if (requests[j].startFloor > i) {
                    break;
                } else if (requests[j].startFloor == i) {
                    printf("电梯停留在第%d层，乘客准备从%d楼到达%d楼\n", elevator.currentFloor, requests[j].startFloor, requests[j].destinationFloor);
                    numRequests--;

                    // 将乘客请求从数组中删除
                    for (int k = j; k < numRequests; k++) {
                        requests[k] = requests[k + 1];
                    }
                }
            }

            elevator.currentFloor = i;
        }

        // 电梯向下运行
        for (i = elevator.currentFloor; i >= 1; i--) {
            // 检查是否有乘客在当前楼层上电梯
            for (j = 0; j < numRequests; j++) {
                if (requests[j].startFloor == i) {
                    if (elevator.passengers < MAX_CAPACITY)
                    {
                    printf("电梯停留在第%d层，乘客准备从%d楼到达%d楼\n", elevator.currentFloor, requests[j].startFloor, requests[j].destinationFloor);
                    elevator.passengers++;
                    numRequests--;
                    }

                    // 将乘客请求从数组中删除
                    for (int k = j; k < numRequests; k++) {
                        requests[k] = requests[k + 1];
                    }
                }
            }
            
            // 检查是否有乘客在当前楼层按下电梯按钮
            for (j = 0; j < numRequests; j++) {
                if (requests[j].startFloor < i) {
                    break;
                } else if (requests[j].startFloor == i) {
                    printf("电梯停留在第%d层，乘客准备从%d楼到达%d楼\n", elevator.currentFloor, requests[j].startFloor, requests[j].destinationFloor);
                    numRequests--;

                    // 将乘客请求从数组中删除
                    for (int k = j; k < numRequests; k++) {
                        requests[k] = requests[k + 1];
                    }
                }
            }

            elevator.currentFloor = i;
        }
    }

    return 0;
}