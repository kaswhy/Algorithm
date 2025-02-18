-- 노선, 
-- 총 누계 거리(역 사이 거리의 총합) -> TOTAL_DISTANCE, \
-- 평균 역 사이 거리 -> AVERAGE_DISTANCE (소수 셋째 자리 반올림, 단위 출력)
-- 노선 별로!
-- 총 누계거리를 기준으로 내림차순 정렬
SELECT ROUTE, 
       CONCAT(ROUND(SUM(D_BETWEEN_DIST), 1), "km") AS TOTAL_DISTANCE, 
       CONCAT(ROUND(AVG(D_BETWEEN_DIST), 2), "km") AS AVERAGE_DISTANCE
FROM SUBWAY_DISTANCE
GROUP BY ROUTE
ORDER BY ROUND(SUM(D_BETWEEN_DIST), 2) DESC