#include <stdio.h>

int main() {
    int frameTable[20], pageRequests[50], pageFaultCount = 0, pageNotFound, frameCount, numPages, i, j, frameIndex = 0, frameIndexToReplace, temp, usageCounts[20], tempUsageCounts[20];

    // Input: Number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    // Input: Reference string
    printf("Enter the reference string: ");
    for (i = 0; i < numPages; i++)
        scanf("%d", &pageRequests[i]);

    // Input: Number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);

    frameTable[frameIndex] = pageRequests[frameIndex];
    printf("\n\t%d\n", frameTable[frameIndex]);
    pageFaultCount++;
    frameIndex++;

    for (i = 1; i < numPages; i++) {
        pageNotFound = 1;

        // Check if the page is present in frames
        for (j = 0; j < frameCount; j++) {
            if (pageRequests[i] == frameTable[j]) {
                pageNotFound = 0;
                usageCounts[j]++;
                break;
            }
        }

        if (pageNotFound) { // Page not found in frames
            pageFaultCount++;
            if (frameIndex < frameCount) { // There are still available frames
                frameTable[frameIndex] = pageRequests[i];
                usageCounts[frameIndex] = 1;
                frameIndex++;
                for (j = 0; j < frameIndex; j++)
                    printf("\t%d", frameTable[j]);
                printf("\n");
            } else {
                // Find the least frequently used page to replace
                for (j = 0; j < frameCount; j++) {
                    tempUsageCounts[j] = usageCounts[j];
                }

                // Sort the usageCounts to find the least frequent page
                for (j = 0; j < frameCount; j++) {
                    for (int k = j; k < frameCount; k++) {
                        if (tempUsageCounts[j] > tempUsageCounts[k]) {
                            temp = tempUsageCounts[j];
                            tempUsageCounts[j] = tempUsageCounts[k];
                            tempUsageCounts[k] = temp;
                        }
                    }
                }

                // Find the frame index to replace
                for (j = 0; j < frameCount; j++) {
                    if (usageCounts[j] == tempUsageCounts[0]) {
                        frameIndexToReplace = j;
                        break;
                    }
                }

                // Replace the least frequent page
                frameTable[frameIndexToReplace] = pageRequests[i];
                usageCounts[frameIndexToReplace] = 1;
                for (j = 0; j < frameCount; j++) {
                    printf("\t%d", frameTable[j]);
                }
                printf("\n");
            }
        }
    }

    printf("\nThe number of page faults is %d", pageFaultCount);

    return 0;
}
