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

% for(i = 1:100)
%     [threshold4(i), finalD] = kmean_dk(y2(893:1192))
% end
% 
% test = y2(893:1192);
% for m = 1:200
%     for n = 1:200
%         for(i = 1:length(test))
%             if(abs(test(i) - m) < abs(test(i) - n))
%                 testCluster(i) = false; 
%             else
%                 testCluster(i) = true;
%             end
%         end
%         D2(m,n) = sum(abs(test(testCluster == false) - m)) + sum(abs(test(testCluster == true) - n));
%     end
% end
% 
% surf(D2)
% 
% D3 = sort(D2(:));
% 
% for i = 1:500
%     [a,b] = find(D2 == D3(i));
% end
    
    
N = 100;
threshold(1:N-1) = 0;
threshold2(1:N-1) = 0;
threshold3(1:N-1) = 0;


for i = 1:length(x) - N +1
    [threshold(i+N-1), finalD2] = kmean_dk(y2(i:i+N-1));
    [IDX, c] = kmeans(y2(i:i+N-1), 2, 'start', 'uniform');
    threshold2(i+N-1) = mean(c);
    threshold3(i+N-1) = mean(y2(i:i+N-1));
end

plot(x, y2, x, threshold, x, threshold2, x, threshold3)
