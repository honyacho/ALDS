import Data.Array.MArray
import Data.Array.IO
import Data.List.Split
import Data.Int

type Int32Array = IOUArray Int32 Int32
main = do
  num <- fmap (\str -> (read str :: Int32)) getLine
  strLs <- fmap (splitOn " ") getLine
  let xs = fmap (\str -> (read str :: Int32)) strLs
  arr <- newListArray (0, num - 1) xs
  arr' <- getElems arr
  prettyPut arr'
  loop1 1 num arr

loop1 :: Int32 -> Int32 -> Int32Array -> IO ()
loop1 cur to arr
  | cur < to = do
    key <- readArray arr cur
    loop2 (cur-1) arr key
    arr' <- getElems arr
    prettyPut arr'
    loop1 (cur + 1) to arr
  | cur == to = return ()

loop2 :: Int32 -> Int32Array -> Int32 -> IO ()
loop2 cur arr key = do
  if (cur >= 0) then do
    value <- readArray arr cur
    if (value > key) then do
      writeArray arr (cur+1) value
      loop2 (cur-1) arr key
    else
      writeArray arr (cur+1) key
  else
    writeArray arr (cur+1) key

prettyPut xs = do
  let strXs = fmap show xs
  putStrLn $ foldl1 (\x y -> x ++ " " ++ y) strXs
