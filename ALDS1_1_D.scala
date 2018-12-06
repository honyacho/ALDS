object Main {
  def main(args: Array[String]): Unit = {
    val n = readLine.toInt
    val _input = new Array[Int](n)
    1 to n foreach { i => _input(i-1) = readLine.toInt }
    val input = _input.toList
    //println(input)
    val head1 :: head2 :: tail = input

    println(calMaxProf(tail, head2 - head1, math.min(head1, head2), math.max(head1, head2)))
  }

  def calMaxProf(input: List[Int], maxProf: Int, min: Int, max: Int): Int = input match {
    case head :: tail =>
      if (head < min) calMaxProf(tail, maxProf, head, max)
      else if (head - min > maxProf) calMaxProf(tail, head - min, min, head)
      else calMaxProf(tail, maxProf, min, max)
    case Nil =>
      maxProf
  }
}
