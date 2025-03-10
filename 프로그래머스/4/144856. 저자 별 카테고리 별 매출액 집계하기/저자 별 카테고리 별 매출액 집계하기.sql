SELECT A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, 
     SUM(S.SALES * B.PRICE) AS TOTAL_SALES
FROM BOOK_SALES S
INNER JOIN BOOK B
ON S.BOOK_ID = B.BOOK_ID
INNER JOIN AUTHOR A
ON A.AUTHOR_ID = B.AUTHOR_ID
WHERE YEAR(S.SALES_DATE) = 2022 AND MONTH(S.SALES_DATE) = 1
GROUP BY A.AUTHOR_ID, B.CATEGORY
ORDER BY A.AUTHOR_ID, B.CATEGORY DESC;