<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%-- <%@ page session="false" %> --%>

<html>
<head>
	<title>Home</title>
	<link rel="stylesheet" type="text/css" href="/resources/css/crypto.css">
	<link rel="stylesheet" type="text/css" href="/resources/font/font.css">
	<link rel="stylesheet" type="text/css" href="/resources/vendor/bootstrap/css/bootstrap.css">
	<jsp:directive.include file="/WEB-INF/views/common/taglib.jsp" />
	<script type="text/javascript">
	$(document).ready(function(){
//		onAjax();
//		onAjaxForNews();
	})
	
	// 타이머. 1초에 1000.
	//setInterval(() => {
//		onAjax();
// 		onAjaxForNews();
	//}, 5000);
	// ----
	
	// 암호화폐 데이터 가지고 오는 부분.
	function onAjax(){
		$.ajax({
			method: "POST",
			url : "/UpbitData.json",
			dataType: "JSON",
			success: function(result){
				console.log(result);
				onCryptoCurrency(result);
// 				$("#cryptoList").load("/Link/cc0010_CryptoCurrency.do");
			},
			error: function(data){
				/* alert("E" + data); */
			}
		})
	}
	// ----
	
	// 뉴스 데이터 가지고 오는 부분.
	function onAjaxForNews(){
		$.ajax({
			method: "POST",
			url : "/CryptoCurrNews.json",
			dataType: "JSON",
			success: function(result){
				onNewsList(result);
// 				$("#cryptoList").load("/Link/cc0010_CryptoCurrency.do");
			},
			error: function(data){
				/* alert("E" + data); */
			}
		})
	}
	// ----
	
	// 데이터 기반 화면에 그리는 부분.
	function onCryptoCurrency(data){
		var list = data.list;
		
		var table = $("#cryptoList");
		var tbody = table.children("tbody");
		
		if(list.length > 0){
			tbody.children().remove();
			var cell1, cell2, cell3, cell4, cell5, cell6;
			for(var i = 0; i < list.length; i++){
				var item = list[i];
// 				tbody.append("<tr></tr>");
				row = $("<tr>");
				cell1 = $("<td>").addClass("test").text(item.code);	// 종류
				cell2 = $("<td>").text(item.upbitPrice);	// Upbit 가격(국내)
				cell3 = $("<td>").text(item.binancePrice);	// Binance 가격(국외)
				cell4 = $("<td>").text(item.tradePrice);	// 프리미엄(%)
				cell5 = $("<td>").append("<input type='text' value='0'/>");	// 수량
				cell6 = $("<td>").append("<input type='text' value='0'/>");	// 가격
				tbody.append(row).append(cell1, cell2, cell3, cell4, cell5, cell6);
			}			
		}
	}
	// ----
	
	// 데이터 기반 화면에 그리는 부분.
	function onNewsList(data){
		var list = data.newsList;
		
		var table = $("#newsList");
		var cardColumn = table.children("div");
		
		if(list.length > 0){
			cardColumn.children().remove();
			var card
			var cardBody;
			var cell1, cell2, cell3;
			var a;
			for(var i = 0; i < list.length; i++){
				var item = list[i];
				// 첫번째 행.
				card = $("<div>").addClass("card");
				cardColumn.append(card);
				cardBody = $("<div>").addClass("card-body");
				card.append(cardBody);
				cell1 = $("<h5>").addClass("card-title").html(item.title);	// 제목
				cell2 = $("<p>").addClass("card-text").attr("colspan", "2");
				cell3 = $("<small>").addClass("card-text text-secondary").text(item.pubDate);					// 작성일자
				
				a = $("<a>").addClass("text-dark").attr({"href": item.link, "target": "_blank"});
				a.html(item.description);	// 요약 내용.
				cell2.append(a);
				cardBody.append(cell1, cell2, cell3);
			}			
		}
	}
	// ----
	
	</script>
</head>
<body>
<div class="container">
	<header class="blog-header py-3">
        <div class="row flex-nowrap justify-content-between align-items-center">
          <div class="col-2 pt-1">
            <a class="text-muted" href="#">Hello</a>
          </div>
          <div class="col-8 text-center">
            <h1 class="text-dark" style="font-family:Roboto Mono Bold;" >
	            <a href="#">
					Crypto Type and Price Information
				</a>
			</h1>
          </div>
          <div class="col-2 d-flex justify-content-end align-items-center">
            <a class="text-muted" href="#">
              <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="mx-3"><circle cx="10.5" cy="10.5" r="7.5"></circle><line x1="21" y1="21" x2="15.8" y2="15.8"></line></svg>
            </a>
          </div>
        </div>
    </header>
	<div class="nav-scroller py-1 mb-2">
        <nav class="nav d-flex justify-content-between">
          <a class="p-2 text-muted" href="#">World</a>
          <a class="p-2 text-muted" href="#">U.S.</a>
          <a class="p-2 text-muted" href="#">Technology</a>
          <a class="p-2 text-muted" href="#">Design</a>
          <a class="p-2 text-muted" href="#">Culture</a>
          <a class="p-2 text-muted" href="#">Business</a>
          <a class="p-2 text-muted" href="#">Politics</a>
          <a class="p-2 text-muted" href="#">Opinion</a>
          <a class="p-2 text-muted" href="#">Science</a>
          <a class="p-2 text-muted" href="#">Health</a>
          <a class="p-2 text-muted" href="#">Style</a>
          <a class="p-2 text-muted" href="#">Travel</a>
        </nav>
      </div>
	
	<div class="row">
		<table id="cryptoList" class="table">
			<colgroup>
				<col/>
				<col/>
				<col/>
				<col/>
				<col/>
				<col/>
			</colgroup>
		  <thead class="thead-dark">
		    <tr>
		        <th scope="col">종류</th>
				<th scope="col">Upbit 가격(국내)</th>
				<th scope="col">Binance 가격(국외)</th>
				<th scope="col">프리미엄(%)</th>
				<th scope="col">수량</th>
				<th scope="col">가격</th>
		    </tr>
		  </thead>
		  <tbody>
				<tr>
					<td colspan="6">검색된 내역이 없습니다.</td>
				</tr>
		  </tbody>
		</table>	
	</div>
	
	<div class="row bg-dark"  style="margin-top:16px;margin-bottom:16px;">
		<h2 class="text-white" style="font-family:Roboto Mono Bold;padding-left:8px;" >Crypto News</h2>
	</div>
	<div id="newsList" class="row">
		<div class="card-columns">
			<p>검색된 내역이 없습니다.</p>
		</div>
	</div>

</div>

</body>
</html>
