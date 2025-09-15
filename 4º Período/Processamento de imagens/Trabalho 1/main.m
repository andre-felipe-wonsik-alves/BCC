entrada = imread("./Imagens/tungsten_filament_shaded.tif");
sombra = imread("./Imagens/tungsten_sensor_shading.tif");

imshow(entrada);

entrada_double = im2double(entrada);
sombra_double = im2double(sombra);

saida = entrada_double ./ sombra_double;

figure, imshow(saida);
