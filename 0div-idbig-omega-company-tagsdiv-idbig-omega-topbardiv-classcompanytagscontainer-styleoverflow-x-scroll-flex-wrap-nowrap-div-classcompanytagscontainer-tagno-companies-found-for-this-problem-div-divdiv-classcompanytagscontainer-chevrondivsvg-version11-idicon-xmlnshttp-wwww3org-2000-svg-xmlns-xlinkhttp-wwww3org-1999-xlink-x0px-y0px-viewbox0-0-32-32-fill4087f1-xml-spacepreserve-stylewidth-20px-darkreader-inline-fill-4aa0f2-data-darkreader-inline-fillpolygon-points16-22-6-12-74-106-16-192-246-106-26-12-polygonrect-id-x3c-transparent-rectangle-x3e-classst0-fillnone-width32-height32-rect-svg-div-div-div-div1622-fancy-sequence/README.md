<h2><a href="https://leetcode.com/problems/fancy-sequence/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1622. Fancy Sequence</a></h2><h3>Hard</h3><hr><div><p>Write an API that generates fancy sequences using the <code>append</code>, <code>addAll</code>, and <code>multAll</code> operations.</p>

<p>Implement the <code>Fancy</code> class:</p>

<ul>
	<li><code>Fancy()</code> Initializes the object with an empty sequence.</li>
	<li><code>void append(val)</code> Appends an integer <code>val</code> to the end of the sequence.</li>
	<li><code>void addAll(inc)</code> Increments all existing values in the sequence by an integer <code>inc</code>.</li>
	<li><code>void multAll(m)</code> Multiplies all existing values in the sequence by an integer <code>m</code>.</li>
	<li><code>int getIndex(idx)</code> Gets the current value at index <code>idx</code> (0-indexed) of the sequence <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>. If the index is greater or equal than the length of the sequence, return <code>-1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong>Output</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong>Explanation</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -&gt; [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -&gt; [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -&gt; [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -&gt; [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= val, inc, m &lt;= 100</code></li>
	<li><code>0 &lt;= idx &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls total will be made to <code>append</code>, <code>addAll</code>, <code>multAll</code>, and <code>getIndex</code>.</li>
</ul>
</div>