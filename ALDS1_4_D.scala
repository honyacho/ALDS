import scala.io.StdIn

object Main {
  def main(args: Array[String]): Unit = {
    val Array(n, k) = StdIn.readLine.split(' ').map(_.toInt)
    val ar = (1 to n map (_ => StdIn.readLine.toInt)).toArray
    var l = 1
    var r = ar.sum
    var ans = 0

    while (l < r) {
      ans = (r + l) / 2
      if (alloc(ar, n, k, ans)) {
        r = ans
      } else {
        l = ans + 1
      }
    }
    println(l)
  }

  def alloc(arr: Array[Int], len: Int, k: Int, maxAlloc: Int): Boolean = {
    var cache = 0
    var j = 1
    for (a <- arr) {
      if (cache + a <= maxAlloc) {
        cache += a
      } else if (a <= maxAlloc && j < k) {
        cache = a
        j += 1
      } else {
        return false
      }
    }
    true
  }
}
