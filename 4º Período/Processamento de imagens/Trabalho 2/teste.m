input = imread("./pollen.jpg");

% --- NÃO mostre output aqui (ainda não existe) ---
% figure, imshow(output);

zero_matrix = zeros(size(input), "uint16");  % opcional, você não usa depois

start_x = 87;   start_y = 2; % escolhido olhando no GIMP
end_x = 139;  end_y = 220;

first_x = 0;    first_y = 0;
last_x = 255;  last_y = 255;

% LUT da transformação
T = zeros(256, 1, "uint8");

for r = first_x:start_x
  s = first_y + (start_y - first_y) * (r - first_x) / (start_x - first_x);
  if s < 0, s = 0; end
  if s > 255, s = 255; end
  T(r + 1) = uint8(round(s));
endfor

for r = start_x:end_x
  s = start_y + (end_y - start_y) * (r - start_x) / (end_x - start_x);
  if s < 0, s = 0; end
  if s > 255, s = 255; end
  T(r + 1) = uint8(round(s));
endfor

for r = end_x:last_x
  s = end_y + (last_y - end_y) * (r - end_x) / (last_x - end_x);
  if s < 0, s = 0; end
  if s > 255, s = 255; end
  T(r + 1) = uint8(round(s));
endfor

% (A) AQUI: plot da CURVA T(r)
figure;
plot(0:255, double(T));              % curva de transformação
hold on;
plot([0 255], [0 255], '--');        % linha identidade (referência)
hold off;

% Aplicar LUT
if size(input, 3) == 1
  output = T(double(input) + 1);
else
  output = zeros(size(input), "uint8");
  for c = 1:size(input, 3)
    output(:, :, c) = T(double(input(:, :, c)) + 1);
  endfor
endif

% Mostrar imagem resultante
figure, imshow(output);

% (B) AQUI: plot de HISTOGRAMAS antes vs depois (sem usar funções extras)
% Conta frequências de 0..255 de forma simples
counts_in  = accumarray(double(input(:))  + 1, 1, [256, 1]);
counts_out = accumarray(double(output(:)) + 1, 1, [256, 1]);

figure;
plot(0:255, counts_in);              % histograma da entrada
hold on;
plot(0:255, counts_out);             % histograma da saída
hold off;

