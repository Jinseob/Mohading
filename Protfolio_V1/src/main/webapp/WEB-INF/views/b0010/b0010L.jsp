<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%-- <%@ page session="false" %> --%>

<html>
<head>
	<title>Mohading Blog</title>
	<jsp:directive.include file="/WEB-INF/views/common/taglib.jsp" />
	<script type="text/javascript">
	$(document).ready(function(){
		
	})
	
	/* 상세 화면 */
	function fncGetDetail(key){
		$("#id").val(key);
		$("#frm").attr({target : "_self", action : "./b0010D.do", method : "post"});
		$("#frm").submit();
	}
	
	/* 신규 화면 */
	function fncCreate(){
		$("#frm").attr({target : "_self", action : "./b0010INS.do", method : "post"});
		$("#frm").submit();
	}
	
	/* 화면 이동 */
	function fncGoPage(page){
		$("#frm").attr({target : "_self", action : "./" + page, method : "post"});
		$("#frm").submit();
	}
	</script>
</head>
<body>

<form id="frm" name="frm">
	<input type="hidden" id="id" name="id">
</form>
<div class="container">
	<!-- Header -->
	<jsp:include page="/WEB-INF/views/common/header.jsp" />

<!--   <div class="jumbotron p-3 p-md-5 text-white rounded bg-dark">
    <div class="col-md-6 px-0">
      <h1 class="display-4 font-italic">Title of a longer featured blog post</h1>
      <p class="lead my-3">Multiple lines of text that form the lede, informing new readers quickly and efficiently about what's most interesting in this post's contents.</p>
      <p class="lead mb-0"><a href="#" class="text-white font-weight-bold">Continue reading...</a></p>
    </div>
  </div> -->

  <!-- <div class="row mb-2">
    <div class="col-md-4">
      <div class="card flex-md-row mb-4 box-shadow h-md-250">
        <div class="card-body d-flex flex-column align-items-start">
          <strong class="d-inline-block mb-2 text-primary">World</strong>
          <h3 class="mb-0">
            <a class="text-dark" href="#">Featured post</a>
          </h3>
          <div class="mb-1 text-muted">Nov 12</div>
          <p class="card-text mb-auto">This is a wider card with supporting text below as a natural lead-in to additional content.</p>
          <a href="#">Continue reading</a>
        </div>
      </div>
    </div>
    <div class="col-md-4">
      <div class="card flex-md-row mb-4 box-shadow h-md-250">
        <div class="card-body d-flex flex-column align-items-start">
          <strong class="d-inline-block mb-2 text-success">Design</strong>
          <h3 class="mb-0">
            <a class="text-dark" href="#">Post title</a>
          </h3>
          <div class="mb-1 text-muted">Nov 11</div>
          <p class="card-text mb-auto">This is a wider card with supporting text below as a natural lead-in to additional content.</p>
          <a href="#">Continue reading</a>
        </div>
      </div>
    </div>
    <div class="col-md-4">
      <div class="card flex-md-row mb-4 box-shadow h-md-250">
        <div class="card-body d-flex flex-column align-items-start">
          <strong class="d-inline-block mb-2 text-success">Design</strong>
          <h3 class="mb-0">
            <a class="text-dark" href="#">Post title</a>
          </h3>
          <div class="mb-1 text-muted">Nov 11</div>
          <p class="card-text mb-auto">This is a wider card with supporting text below as a natural lead-in to additional content.</p>
          <a href="#">Continue reading</a>
        </div>
      </div>
    </div>
  </div> -->
  
  <div class="row mb-2">
 	<c:choose>
		<c:when test="${fn:length(list) > 0 }">
			<c:forEach items="${list }" var="list" varStatus="status">
				<div class="col-md-4">
			      <div class="card flex-md-row mb-4 box-shadow h-md-250">
			        <div class="card-body d-flex flex-column align-items-start">
			          <strong class="d-inline-block mb-2 text-primary">자유</strong>
			          <h3 class="mb-0">
			            <a class="text-dark" href="#">${list.title}</a>
			          </h3>
			          <div class="mb-1 text-muted">${list.cre_dt}</div>
			          <p class="card-text mb-auto">${list.content}</p>
			          <a href="#" onclick="javascript:fncGetDetail('${list.id}');">Continue reading</a>
			        </div>
			      </div>
			    </div>
			</c:forEach>
		</c:when>
		<c:otherwise>
			<div>검색된 자료가 없습니다</div>
		</c:otherwise>
	</c:choose>
  </div>
</div>
	
	<!-- Footer -->
	<jsp:include page="/WEB-INF/views/common/footer.jsp" />
</body>
</html>
