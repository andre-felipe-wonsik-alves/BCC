input = imread("./pollen.jpg");
figure, imshow(input);

start_x = 87;   start_y = 2; % escolhido olhando no GIMP
end_x = 139;  end_y = 220;

first_x = 0;    first_y = 0;
last_x = 255;  last_y = 255;

colors = zeros(256, 1, "uint8");

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

if size(input, 3) == 1
  output = T(double(input) + 1);
else
  for c = 1:size(input, 3)
    output(:, :, c) = T(double(input(:, :, c)) + 1);
  endfor
endif

figure, imshow(output);
