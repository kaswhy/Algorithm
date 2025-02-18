-- 2022년도 한해 평가 점수가 가장 높은 사원 정보
-- 점수(상반기+하반기) -> SCORE, 사번, 성명, 직책, 이메일

SELECT SUM(H.SCORE) AS SCORE, H.EMP_NO, E.EMP_NAME, E.POSITION, E.EMAIL
FROM HR_GRADE AS H
JOIN HR_EMPLOYEES AS E ON E.EMP_NO = H.EMP_NO
GROUP BY H.EMP_NO
ORDER BY SUM(H.SCORE) DESC
LIMIT 1