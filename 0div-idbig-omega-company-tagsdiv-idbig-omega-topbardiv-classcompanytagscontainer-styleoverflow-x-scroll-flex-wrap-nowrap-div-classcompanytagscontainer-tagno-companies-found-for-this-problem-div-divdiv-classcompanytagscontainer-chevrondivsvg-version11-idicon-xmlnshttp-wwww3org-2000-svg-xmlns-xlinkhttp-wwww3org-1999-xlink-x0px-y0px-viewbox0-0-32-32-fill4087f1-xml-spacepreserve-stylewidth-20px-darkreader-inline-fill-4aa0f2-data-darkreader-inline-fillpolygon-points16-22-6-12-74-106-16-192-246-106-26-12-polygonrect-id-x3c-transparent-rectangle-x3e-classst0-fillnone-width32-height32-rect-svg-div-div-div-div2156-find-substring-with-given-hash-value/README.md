<h2><a href="https://leetcode.com/problems/find-substring-with-given-hash-value/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px; --darkreader-inline-fill: #4aa0f2;" data-darkreader-inline-fill=""><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2156. Find Substring With Given Hash Value</a></h2><h3>Hard</h3><hr><div><p>The hash of a <strong>0-indexed</strong> string <code>s</code> of length <code>k</code>, given integers <code>p</code> and <code>m</code>, is computed using the following function:</p>

<ul>
	<li><code>hash(s, p, m) = (val(s[0]) * p<sup>0</sup> + val(s[1]) * p<sup>1</sup> + ... + val(s[k-1]) * p<sup>k-1</sup>) mod m</code>.</li>
</ul>

<p>Where <code>val(s[i])</code> represents the index of <code>s[i]</code> in the alphabet from <code>val('a') = 1</code> to <code>val('z') = 26</code>.</p>

<p>You are given a string <code>s</code> and the integers <code>power</code>, <code>modulo</code>, <code>k</code>, and <code>hashValue.</code> Return <code>sub</code>,<em> the <strong>first</strong> <strong>substring</strong> of </em><code>s</code><em> of length </em><code>k</code><em> such that </em><code>hash(sub, power, modulo) == hashValue</code>.</p>

<p>The test cases will be generated such that an answer always <strong>exists</strong>.</p>

<p>A <b>substring</b> is a contiguous non-empty sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
<strong>Output:</strong> "ee"
<strong>Explanation:</strong> The hash of "ee" can be computed to be hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0. 
"ee" is the first substring of length 2 with hashValue 0. Hence, we return "ee".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
<strong>Output:</strong> "fbx"
<strong>Explanation:</strong> The hash of "fbx" can be computed to be hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 31<sup>2</sup>) mod 100 = 23132 mod 100 = 32. 
The hash of "bxz" can be computed to be hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 31<sup>2</sup>) mod 100 = 25732 mod 100 = 32. 
"fbx" is the first substring of length 3 with hashValue 32. Hence, we return "fbx".
Note that "bxz" also has a hash of 32 but it appears later than "fbx".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= power, modulo &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= hashValue &lt; modulo</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
	<li>The test cases are generated such that an answer always <strong>exists</strong>.</li>
</ul>
</div>