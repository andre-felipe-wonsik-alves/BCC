import os
import cv2
import numpy as np

DIR_PATH = "./data/digitos_new/samples"


def zoneamento_3x3(image):
    height, width = image.shape

    zone_height = height // 3
    zone_width = width // 3

    features = []

    for row in range(3):
        for col in range(3):
            y1 = row * zone_height
            y2 = (row + 1) * zone_height

            x1 = col * zone_width
            x2 = (col + 1) * zone_width

            zone = image[y1:y2, x1:x2]

            pretos = np.sum(zone == 0)
            brancos = np.sum(zone == 255)

            features.append(pretos)
            features.append(brancos)

    return features


with open("dataset.csv", "w") as output:
    output.write(f"num_preto_1;num_branco_1;num_preto_2;num_branco_2;num_preto_3;num_branco_3;num_preto_4;num_branco_4;num_preto_5;num_branco_5;num_preto_6;num_branco_6;num_preto_7;num_branco_7;num_preto_8;num_branco_9;label\n")
    
    for label in os.listdir(DIR_PATH):

        label_path = os.path.join(DIR_PATH, label)

        if not os.path.isdir(label_path):
            continue


        for file_name in os.listdir(label_path):

            file_path = os.path.join(label_path, file_name)

            image = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)

            if image is None:
                continue

            features = zoneamento_3x3(image)

            linha = ";".join(map(str, features))
            linha += f";{label}\n"

            output.write(linha)
