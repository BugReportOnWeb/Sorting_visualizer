#include "SortingAlgo.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define NUM_BARS 50
#define BAR_WIDTH (SCREEN_WIDTH / NUM_BARS)


int partition(int arr[], int low, int high, SDL_Renderer *renderer) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            drawBars(renderer, arr);
            SDL_Delay(30);
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    drawBars(renderer, arr);
    SDL_Delay(30);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, SDL_Renderer *renderer) {
    if (low < high) {
        int pi = partition(arr, low, high, renderer);
        quickSort(arr, low, pi - 1, renderer);
        quickSort(arr, pi + 1, high, renderer);
    }
}
