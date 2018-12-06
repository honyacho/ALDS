module Main (main) where
import Control.Monad.State

strToInt str = (read str :: Integer)
getLineInt = fmap strToInt getLine

getLineIntN n = do
  i <- getLineInt
  if (n > 1) then getLineIntN (n-1) >>= (\xs -> return $ i : xs)
  else return $ i : []

calcProfit = do
  (xs, maxProf, minPrice) <- get
  case xs of
    [] -> return maxProf
    first:rest -> do
      if first < minPrice then put (rest, maxProf, first)
      else if (first - minPrice) > maxProf then put (rest, first - minPrice, minPrice)
      else put (rest, maxProf, minPrice)
      calcProfit

main = do
  rowNum <- getLineInt
  ls <- getLineIntN rowNum
  -- putStrLn $ show ls
  let first:second:xs = ls
  putStrLn $ show $ evalState calcProfit (xs, second - first, min first second)
