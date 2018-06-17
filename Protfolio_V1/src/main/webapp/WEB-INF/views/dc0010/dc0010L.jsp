<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%-- <%@ page session="false" %> --%>

<html>
<head>
	<title>Home</title>
	<link rel="stylesheet" type="text/css" href="resources/css/style.css">
	<jsp:directive.include file="/WEB-INF/views/common/taglib.jsp" />
	<script type="text/javascript">

	</script>
</head>
<body>
<h1>
	Hello world!
</h1>

<table>
	<caption>검색어 순위</caption>
	<colgroup>
		<col style="width: 100px;" />
		<col style="width: 100px;" />
	</colgroup>
	<thead>
		<tr>
			<th scope="col">순위</th>
			<th scope="col">검색어</th>
		</tr>
	</thead>
	<tbody>
		<c:choose>
			<c:when test="${fn:length(list) > 0 }">
				<c:forEach items="${list }" var="list" varStatus="status">
					<tr>
						<td>${list.rank}</td>
						<td>${list.keyword}</td>
					</tr>
				</c:forEach>
			</c:when>
			<c:otherwise>
				<tr>
					<td colspan="2">검색된 자료가 없습니다</td>
				</tr>
			</c:otherwise>
		</c:choose>
	</tbody>
</table>
</body>
</html>
