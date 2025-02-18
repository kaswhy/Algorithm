-- 잡은 수, 최대 길이, 물고기 종류
-- 조건) 평균 길이가 33cm 이상
-- 분류) 종류 별로
-- 정렬) 종류, 오름차순
SELECT COUNT(*) AS FISH_COUNT,
    MAX(CASE
            WHEN LENGTH IS NULL OR LENGTH <= 10 THEN 10
            ELSE LENGTH
        END) AS MAX_LENGTH,
    FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(LENGTH) >= 33
ORDER BY FISH_TYPE