import numpy as np

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        imgnp_pad = np.zeros((m + 2, n + 2), dtype=np.uint16)
        imgnp_pad[1:-1, 1:-1] = np.asarray(img, dtype=np.uint16)
        counter_pad = np.zeros((m + 2, n + 2), dtype=np.uint16)
        counter_pad[1:-1, 1:-1] = 1
        imgnp = np.zeros((m, n), dtype=np.uint16)
        counter = np.zeros((m, n), dtype=np.uint16)
        for i in range(3):
            for j in range(3):
                imgnp += imgnp_pad[i:i + m, j:j + n]
                counter += counter_pad[i:i + m, j:j + n]
        return (imgnp // counter).tolist()
