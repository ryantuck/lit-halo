data = csvread('heartbeat amp data 40sec.csv');
data = data(:, 1:7)/4;

fs = 1/50;

x = 0:fs:(length(data(:,1))-1)*fs;

y1 = data(:,1);
y2 = data(:,2);
y3 = data(:,3);
y4 = data(:,4);
y5 = data(:,5);
y6 = data(:,6);
y7 = data(:,7);

for(i = 1:30)
threshold = kmean_dk(y2(1100:1199))
end


N = 300;
threshold(1:N-1) = 0;
threshold2(1:N-1) = 0;
threshold3(1:N-1) = 0;


[IDX, C] = kmeans(y2, 2);

for i = 1:length(x) - N
    threshold(i+N-1) = kmean_dk(y2(i:i+N-1));
    [IDX, c] = kmeans(y2(i:i+N-1), 2, 'start', 'uniform');
    threshold2(i+N-1) = mean(c);
    threshold3(i+N-1) = mean(y2(i:i+N-1));
end

plot(x, y2, x, threshold, x, threshold2, x, threshold3)
